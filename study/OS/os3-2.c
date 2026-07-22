#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int PAGESIZE;
int PAS_FRAMES;
int VAS_PAGES;

#define PTE_SIZE (4)
#define PAGE_INVALID (0)
#define PAGE_VALID (1)

#define PAGETABLE_FRAMES (VAS_PAGES * PTE_SIZE / PAGESIZE)

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
    int replacements;
} process;

static unsigned char *pas_memory = NULL;
static frame *frames = NULL;
static int next_free_frame = 0;
static int first_data_frame = 0;
static int *frames_pid = NULL;  //소유 pid
static int *frames_vpn = NULL;  //담은 페이지
static int *frames_timestamp = NULL; //적재 시각
static int global_tick = 0;

static int alloc_frames(int count) {
    int base;
    if (next_free_frame + count > PAS_FRAMES)
        return -1;
    base = next_free_frame;
    next_free_frame += count;
    return base;
}

static pte *get_pte(int pt_base, int page) {
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
        procs[n].replacements = 0;
        n++;
    }
    *out = procs;
    return n;
}

static void init_pas(void) {
    int i;
    
    pas_memory = malloc((size_t)PAGESIZE * PAS_FRAMES);
    frames = malloc(sizeof(frame) * PAS_FRAMES);
    frames_pid = malloc(sizeof(int) * PAS_FRAMES);
    frames_vpn = malloc(sizeof(int) * PAS_FRAMES);
    frames_timestamp = malloc(sizeof(int) * PAS_FRAMES);
    for (i = 0; i < PAS_FRAMES; i++) {
        frames[i].b = pas_memory + (size_t)i * PAGESIZE;
        frames_pid[i] = -1;
        frames_vpn[i] = -1;
        frames_timestamp[i] = -1;
    }
}

static void init_page_tables(process *procs, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int base = alloc_frames(PAGETABLE_FRAMES);
        procs[i].pt_base = base;
        procs[i].allocated_frames = PAGETABLE_FRAMES;
        
        memset(frames[base].b, 0, (size_t)PAGETABLE_FRAMES * PAGESIZE);
    }
    first_data_frame = next_free_frame;
}

static process *find_process(process *procs, int n, int pid) {
    int i;
    for (i = 0; i < n; i++) {
        if (procs[i].pid == pid)
            return &procs[i];
    }
    return NULL;
}

static int find_fifo_victim(void) {
    int f, victim = -1, min_ts = INT_MAX;
    for (f = first_data_frame; f < PAS_FRAMES; f++) {
        if (frames_pid[f] >= 0 && frames_timestamp[f] < min_ts) {
            min_ts = frames_timestamp[f];
            victim = f;
        }
    }
    return victim;
}

static void load_frame(int f, int pid, int page) {
    frames_pid[f] = pid;
    frames_vpn[f] = page;
    frames_timestamp[f] = global_tick++;
}

static void run_simulation(process *procs, int n) {
    int ref_idx, i, max_len = 0;

    for (i = 0; i < n; i++)
        if (procs[i].ref_len > max_len)
            max_len = procs[i].ref_len;

    for (ref_idx = 0; ref_idx < max_len; ref_idx++) {
        for (i = 0; i < n; i++) {
            int page, f;
            pte *e;

            if (ref_idx >= procs[i].ref_len)
                continue;
            
            page = procs[i].references[ref_idx];
            e = get_pte(procs[i].pt_base, page);

            if (e->vflag == PAGE_VALID) {
                e->ref++;

                procs[i].references_done++;
                continue;
            }

            f = alloc_frames(1);
            if (f < 0) {  // free frame 없으면 교체
                int victim = find_fifo_victim();
                process *owner = find_process(procs, n, frames_pid[victim]);
                pte *ve = get_pte(owner->pt_base, frames_vpn[victim]);

                ve->vflag = PAGE_INVALID;
                ve->frame = 0;
                ve->ref = 0;
                owner->allocated_frames--;

                procs[i].replacements++;
                f = victim;  //fault에 victim 할당
            }

            e->frame = (unsigned char)f;
            e->vflag = PAGE_VALID;
            e->ref = 1;
            procs[i].allocated_frames++;
            procs[i].page_faults++;

            load_frame(f, procs[i].pid, page);

            procs[i].references_done++;
        }
    }
}

static void print_results(process *procs, int n) {
    int i, page;
    int total_alloc = 0, total_pf = 0, total_ref = 0, total_repl = 0;

    for (i = 0; i < n; i++) {
        printf("** Process %03d: Allocated Frames=%03d PageFaults/References=%03d/%03d Replacements=%03d\n", procs[i].pid, procs[i].allocated_frames, procs[i].page_faults, procs[i].references_done, procs[i].replacements);

        for (page = 0; page < VAS_PAGES; page++) {
            pte *e = get_pte(procs[i].pt_base, page);
            if (e->vflag == PAGE_VALID)
                printf("%03d -> %03d REF=%03d\n", page, e->frame, e->ref);
        }
        total_alloc += procs[i].allocated_frames;
        total_pf += procs[i].page_faults;
        total_ref += procs[i].references_done;
        total_repl += procs[i].replacements;
    }
    printf("Total: Allocated Frames=%03d Page Faults/References=%03d/%03d Replacements=%03d\n", total_alloc, total_pf, total_ref, total_repl);
}

static void cleanup(process *procs, int n) {
    int i;
    for (i = 0; i < n; i++)
        free(procs[i].references);
    free(procs);
    free(frames);
    free(frames_pid);
    free(frames_vpn);
    free(frames_timestamp);
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