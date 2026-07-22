#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PAGESIZE;
int PAS_FRAMES;
int VAS_PAGES;

#define PTE_SIZE (4)
#define PAGE_INVALID (0)
#define PAGE_VALID (1)

#define ENTRIES_PER_FRAME (PAGESIZE / PTE_SIZE)  //프레임당 PTE 수

typedef struct {
    unsigned char frame;
    unsigned char vflag;
    unsigned char ref;
    unsigned char pad;
} pte;

typedef struct {
    unsigned char *b;
} frame;

typedef struct {
    int pid;
    int ref_len;
    unsigned char *references;
    int pt_base;
    int allocated_frames;
    int page_faults;
    int references_done;
} process;

static unsigned char *pas_memory = NULL;
static frame *frames = NULL;
static int next_free_frame = 0;

static int l1_table_frames = 0;
static int l2_table_frames = 0;
static int data_frames = 0;
static int l1_hit = 0, l1_miss = 0;
static int l2_hit = 0, l2_miss = 0;

static int alloc_frames(int count) {
    int base;
    if (next_free_frame + count > PAS_FRAMES)
        return -1;
    base = next_free_frame;
    next_free_frame += count;
    return base;
}

static pte *get_pte(int pt_frame, int idx) {
    return (pte *)(frames[pt_frame].b + idx * PTE_SIZE);
}

static int read_int(int *out) {
    return fread(out, sizeof(int), 1, stdin) == 1 ? 1 : 0;
}

static int load_processes(process **out) {
    process *procs = NULL;
    int n = 0;
    int pid, ref_len;

    while (read_int(&pid)) {
        if (!read_int(&ref_len))
            break;
        
        procs = realloc(procs, sizeof(process) * (n + 1));
        procs[n].pid = pid;
        procs[n].ref_len = ref_len;
        procs[n].references = malloc(ref_len);
        
        if (fread(procs[n].references, 1, ref_len, stdin) != (size_t)ref_len) {
            free(procs[n].references);
            break;
        }
        procs[n].pt_base = -1;
        procs[n].allocated_frames = 0;
        procs[n].page_faults = 0;
        procs[n].references_done = 0;
        n++;
    }
    *out = procs;
    return n;
}

static void init_pas(void) {
    int i;
    
    pas_memory = malloc((size_t)PAGESIZE * PAS_FRAMES);
    frames = malloc(sizeof(frame) * PAS_FRAMES);
    for (i = 0; i < PAS_FRAMES; i++)
        frames[i].b = pas_memory + (size_t)i * PAGESIZE;
}

static void init_page_tables(process *procs, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int base = alloc_frames(1);  //로드 시 L1 PT 프레임 1개 할당
        procs[i].pt_base = base;
        procs[i].allocated_frames = 1;
        
        memset(frames[base].b, 0, PAGESIZE);
        l1_table_frames++;
    }
}

static int access_page(process *proc, int page) {
    int epf = ENTRIES_PER_FRAME;
    int l1_idx = page / epf;
    int l2_idx = page % epf;  //L1, L2 인덱스 분할
    pte *l1e = get_pte(proc->pt_base, l1_idx);
    int l2_base, f;
    pte *l2e;

    if (l1e->vflag == PAGE_VALID) {
        l1_hit++;
    }
    else {  //L1 miss 시 page fault 후 valid
        f = alloc_frames(1);
        if (f < 0)
            return 1;
        l1_miss++;
        memset(frames[f].b, 0, PAGESIZE);  //L2 새 PT 전체 초기화
        l1e->frame = (unsigned char)f;
        l1e->vflag = PAGE_VALID;
        proc->allocated_frames++;
        proc->page_faults++;
        l2_table_frames++;
    }

    l2_base = l1e->frame;
    l2e = get_pte(l2_base, l2_idx);

    if (l2e->vflag == PAGE_VALID) {  //hit
        l2_hit++;
        l2e->ref++;
    }
    else {  //miss, page fault
        f = alloc_frames(1);
        if (f < 0)
            return 1;
        l2_miss++;
        l2e->frame = (unsigned char)f;
        l2e->vflag = PAGE_VALID;
        l2e->ref = 1;
        proc->allocated_frames++;
        proc->page_faults++;
        data_frames++;
    }
    proc->references_done++;
    return 0;
}

static void run_simulation(process *procs, int n) {
    int ref_idx, i, max_len = 0;

    for (i = 0; i < n; i++)
        if (procs[i].ref_len > max_len)
            max_len = procs[i].ref_len;

    for (ref_idx = 0; ref_idx < max_len; ref_idx++) {
        for (i = 0; i < n; i++) {
            if (ref_idx >= procs[i].ref_len)
                continue;
            if (access_page(&procs[i], procs[i].references[ref_idx])) {
                printf("Out of memory!!\n");
                return;
            }
        }
    }
}

static void print_results(process *procs, int n) {
    int i, l1_idx, l2_idx, epf = ENTRIES_PER_FRAME;
    int total_alloc = 0, total_pf = 0, total_ref = 0;

    for (i = 0; i < n; i++) {
        printf("** Process %03d: Allocated Frames=%03d PageFaults/References=%03d/%03d\n", procs[i].pid, procs[i].allocated_frames, procs[i].page_faults, procs[i].references_done);

        for (l1_idx = 0; l1_idx < epf; l1_idx++) {
            pte *l1e = get_pte(procs[i].pt_base, l1_idx);
            if (l1e->vflag != PAGE_VALID)
                continue;
            printf("(L1PT) %03d -> %03d\n", l1_idx, l1e->frame);

            for (l2_idx = 0; l2_idx < epf; l2_idx++) {
                pte *l2e = get_pte(l1e->frame, l2_idx);
                if (l2e->vflag == PAGE_VALID)
                    printf("(L2PT) %03d -> %03d REF=%03d\n", l1_idx * epf + l2_idx, l2e->frame, l2e->ref);
            }
        }
        total_alloc += procs[i].allocated_frames;
        total_pf += procs[i].page_faults;
        total_ref += procs[i].references_done;
    }
    printf("Total: Allocated Frames=%03d Page Faults/References=%03d/%03d\n", total_alloc, total_pf, total_ref);
    printf("L1 table frames = %03d\n", l1_table_frames);
    printf("L2 table frames = %03d\n", l2_table_frames);
    printf("Data frames     = %03d\n", data_frames);
    printf("Page table frames = %03d\n", l1_table_frames + l2_table_frames);
    printf("L1 hit/miss      = %03d/%03d\n", l1_hit, l1_miss);
    printf("L2 hit/miss      = %03d/%03d\n", l2_hit, l2_miss);
}

static void cleanup(process *procs, int n) {
    int i;
    for (i = 0; i < n; i++)
        free(procs[i].references);
    free(procs);
    free(frames);
    free(pas_memory);
}

int main(void)
{
    process * procs = NULL;
    int n;

    if (!read_int(&PAGESIZE) || !read_int(&PAS_FRAMES) || !read_int(&VAS_PAGES)) {
        fprintf(stderr, "Failed to read system parameters\n");
        return 1;
    }

    n = load_processes(&procs);

    init_pas();
    init_page_tables(procs, n);

    run_simulation(procs, n);

    print_results(procs, n);
    cleanup(procs, n);

    return 0;
}