#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PAGESIZE;
int PAS_FRAMES;
int VAS_PAGES;

#define PTE_SIZE (4)
#define PAGE_FRAMES (0)
#define PAGE_VALID (1)

#define PAGETABLE_FRAMES (VAS_PAGES * PTE_SIZE / PAGESIZE)

typedef struct {  // Page Table Entry, 4Byte
    unsigned char frame;
    unsigned char vflag;
    unsigned char ref;
    unsigned char pad;
} pte;

typedef struct {
    unsigned char *b;
} frame;

typedef struct {  //
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

static int alloc_frames(int count) {
    int base;
    if (next_free_frame + count > PAS_FRAMES)
        return -1;
    base = next_free_frame;
    next_free_frame += count;
    return base;
}

static pte *get_pte(int pt_base, int page) {  //page*PTE_SIZE바이트의 오프셋으로 PTE에 접근
    return (pte *)(frames[pt_base].b + page * PTE_SIZE);
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
    frames = malloc(sizeof(frame) * PAS_FRAMES);  //페이지테이블 연속성 보장
    for (i = 0; i < PAS_FRAMES; i++)
        frames[i].b = pas_memory + (size_t)i * PAGESIZE;
}

static void init_page_tables(process *procs, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int base = alloc_frames(PAGETABLE_FRAMES);
        procs[i].pt_base = base;
        procs[i].allocated_frames = PAGETABLE_FRAMES;
        
        memset(frames[base].b, 0, (size_t)PAGETABLE_FRAMES * PAGESIZE);
    }
}

static int run_simulation(process *procs, int n) {
    int ref_idx, i, max_len = 0;

    for (i = 0; i < n; i++)
        if (procs[i].ref_len > max_len)
            max_len = procs[i].ref_len;

    for (ref_idx = 0; ref_idx < max_len; ref_idx++) { //라운드로빈접근
        for (i = 0; i < n; i++) {
            int page;
            pte *e;

            if (ref_idx >= procs[i].ref_len) //끝난 프로세스 skip
                continue;
            
            page = procs[i].references[ref_idx];
            e = get_pte(procs[i].pt_base, page);

            if (e->vflag == PAGE_VALID)  //hit
                e->ref++;
            else {
                int f = alloc_frames(1);
                if (f < 0) {
                    printf("Out of memory!!\n"); //프레임 부족
                    return 1;
                }
                e->frame = (unsigned char)f;
                e->vflag = PAGE_VALID;
                e->ref = 1;

                procs[i].page_faults++;
                procs[i].allocated_frames++;
            }
            procs[i].references_done++;
        }
    }
    return 0;
}

static void print_results(process *procs, int n) {
    int i, page;
    int total_alloc = 0, total_pf = 0, total_ref = 0;

    for (i = 0; i < n; i++) {
        printf("** Process %03d: Allocated Frames=%03d PageFaults/References=%03d/%03d\n", procs[i].pid, procs[i].allocated_frames, procs[i].page_faults, procs[i].references_done);

        for (page = 0; page < VAS_PAGES; page++) {
            pte *e = get_pte(procs[i].pt_base, page);
            if (e->vflag == PAGE_VALID)
                printf("%03d -> %03d REF=%03d\n", page, e->frame, e->ref);
        }
        total_alloc += procs[i].allocated_frames;
        total_pf += procs[i].page_faults;
        total_ref += procs[i].references_done;
    }
    printf("Total: Allocated Frames=%03d Page Faults/References=%03d/%03d\n", total_alloc, total_pf, total_ref);
}

static void cleanup(process *procs, int n) { //할당 메모리 전부 해제
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