#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
 *  Linux-style list (Litmus 제출을 위해 list.h 내용을 인라인화)
 * ============================================================ */
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({                      \
        const __typeof__(((type *)0)->member) *__mptr = (ptr);  \
        (type *)((char *)__mptr - offsetof(type, member)); })

#define LIST_POISON1 ((void *) 0x00100100)
#define LIST_POISON2 ((void *) 0x00200200)

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)
#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

static inline void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next) {
    next->prev = new;
    new->next  = next;
    new->prev  = prev;
    prev->next = new;
}
static inline void list_add(struct list_head *new, struct list_head *head)       { __list_add(new, head, head->next); }
static inline void list_add_tail(struct list_head *new, struct list_head *head)  { __list_add(new, head->prev, head); }

static inline void __list_del(struct list_head *prev, struct list_head *next) {
    next->prev = prev;
    prev->next = next;
}
static inline void list_del(struct list_head *entry) {
    __list_del(entry->prev, entry->next);
    entry->next = LIST_POISON1;
    entry->prev = LIST_POISON2;
}
static inline void list_del_init(struct list_head *entry) {
    __list_del(entry->prev, entry->next);
    INIT_LIST_HEAD(entry);
}
static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define list_for_each_entry(pos, head, member)                                 \
    for (pos = list_entry((head)->next, __typeof__(*pos), member);             \
         &pos->member != (head);                                               \
         pos = list_entry(pos->member.next, __typeof__(*pos), member))

#define list_for_each_entry_safe(pos, n, head, member)                         \
    for (pos = list_entry((head)->next, __typeof__(*pos), member),             \
         n   = list_entry(pos->member.next, __typeof__(*pos), member);         \
         &pos->member != (head);                                               \
         pos = n, n = list_entry(n->member.next, __typeof__(*n), member))

/* ============================================================
 *  시뮬레이터 상수 / 자료형
 * ============================================================ */
#define N_CPU       2        /* 2-2: CPU 두 개 */
#define CS_CLOCKS   10       /* context switching 소요 clock */
#define IDLE_PID    100      /* idle process 전용 PID */
#define IDLE_LEN    1        /* idle operation 길이 (무한 반복) */

#define OP_CPU      0x00
#define OP_IO       0x01
#define OP_IDLE     0xFF

typedef struct {
    unsigned char op;
    unsigned char len;
} code;

typedef struct {
    int pid;
    int arrival_time;
    int code_bytes;
    code *operations;
    int pc;           /* 현재 수행 중인 code tuple 번호 */
    int op_remain;    /* 현재 op의 남은 clock */
    struct list_head job, ready, wait;
} process;

typedef struct {
    int id;                   /* 1-based CPU id (출력용) */
    struct list_head rq;      /* ready queue */
    process *curr;            /* 현재 실행 중인 프로세스 */
    process *next_proc;       /* context switching 중 진입할 대상 */
    int cs_timer;             /* CS 진행중 남은 clock (0 = 진행중 아님) */
    int cs_finalize;          /* 직전 clock 마지막에 CS 종료됨 → 이번 clock 시작 시 finalize */
    int last_pid;             /* "Switched from: X" 에 사용 */
    int io_printed;           /* 현재 op이 IO인 경우 START 출력을 이미 했는지 */
    int idle_clocks;          /* 통계: CPU가 실제 CPU 작업을 수행하지 않은 시간 */
    int util_clocks;          /* 통계: real process의 CPU op를 수행한 clock */
} cpu_t;

/* ============================================================
 *  Helper
 * ============================================================ */

/* idle process 생성 — 모든 CPU는 항상 idle 하나를 ready queue 혹은 curr 로 보유 */
static process *make_idle(void) {
    process *p = (process *)calloc(1, sizeof(process));
    p->pid = IDLE_PID;
    p->arrival_time = 0;
    p->code_bytes = 2;
    p->operations = (code *)calloc(1, sizeof(code));
    p->operations[0].op  = OP_IDLE;
    p->operations[0].len = IDLE_LEN;
    p->pc = 0;
    p->op_remain = 0;
    INIT_LIST_HEAD(&p->job);
    INIT_LIST_HEAD(&p->ready);
    INIT_LIST_HEAD(&p->wait);
    return p;
}

/* 특정 process가 앞으로 수행해야 하는 총 clock 수 (idle 은 0 으로 취급) */
static int remain_time(process *p) {
    if (!p || p->pid == IDLE_PID) return 0;
    int nops = p->code_bytes / 2;
    int sum = 0;
    /* 현재 op 의 남은 길이 */
    if (p->op_remain > 0) sum += p->op_remain;
    /* 다음 op 부터의 총 길이 */
    int start = p->pc + (p->op_remain > 0 ? 1 : 0);
    for (int i = start; i < nops; i++) sum += p->operations[i].len;
    return sum;
}

/* ready queue 에 존재하는 real process 들의 잔여 실행 시간 총합 */
static int rq_remain(struct list_head *rq) {
    int sum = 0;
    process *p;
    list_for_each_entry(p, rq, ready) sum += remain_time(p);
    return sum;
}

/* ready queue 에서 가장 앞의 real process 를 반환 (없으면 NULL) */
static process *first_real(struct list_head *rq) {
    process *p;
    list_for_each_entry(p, rq, ready)
        if (p->pid != IDLE_PID) return p;
    return NULL;
}

/* ready queue 에서 idle process 를 반환 (없으면 NULL) */
static process *first_idle(struct list_head *rq) {
    process *p;
    list_for_each_entry(p, rq, ready)
        if (p->pid == IDLE_PID) return p;
    return NULL;
}

/* 시뮬레이터가 종료 조건을 만족했는지 확인
 *   - job queue 에 real 이 남아있거나,
 *   - CPU 의 curr / next_proc / ready queue 에 real 이 있으면 계속 진행 */
static int any_real_alive(struct list_head *jq, cpu_t cpus[]) {
    if (!list_empty(jq)) return 1;
    for (int i = 0; i < N_CPU; i++) {
        if (cpus[i].curr && cpus[i].curr->pid != IDLE_PID) return 1;
        if (cpus[i].next_proc && cpus[i].next_proc->pid != IDLE_PID) return 1;
        process *p;
        list_for_each_entry(p, &cpus[i].rq, ready)
            if (p->pid != IDLE_PID) return 1;
    }
    return 0;
}

/* ============================================================
 *  초기 로드 & 런타임 arrival 처리
 * ============================================================ */

/* 초기 로드(클럭 0) — 도착시간 0 프로세스들을 load balancing 으로 분배
 *   - 비교 대상에는 각 CPU 의 curr 까지 포함한다 (초기에는 CS 가 없음)
 *   - 동률이면 CPU1 부터 */
static void initial_load(struct list_head *jq, cpu_t cpus[]) {
    process *p, *n;

    /* 1. real 프로세스 (arrival_time == 0) 순서대로 처리 */
    list_for_each_entry_safe(p, n, jq, job) {
        if (p->arrival_time != 0) continue;

        int r[N_CPU];
        for (int i = 0; i < N_CPU; i++)
            r[i] = rq_remain(&cpus[i].rq) + remain_time(cpus[i].curr);

        int target = 0;
        for (int i = 1; i < N_CPU; i++)
            if (r[i] < r[target]) target = i;       /* 동률이면 작은 index 유지 */

        list_del(&p->job);
        INIT_LIST_HEAD(&p->job);

        printf("%04d CPU%d: Loaded PID: %03d\tArrival: %03d\tCodesize: %03d\n",
               0, cpus[target].id, p->pid, p->arrival_time, p->code_bytes);

        if (cpus[target].curr == NULL) {
            cpus[target].curr = p;
            p->op_remain = p->operations[0].len;
            cpus[target].last_pid = p->pid;
        } else {
            list_add_tail(&p->ready, &cpus[target].rq);
        }
    }

    /* 2. idle 프로세스를 각 CPU 에 하나씩 추가 (real 뒤에 출력) */
    for (int i = 0; i < N_CPU; i++) {
        process *idle = make_idle();
        printf("%04d CPU%d: Loaded PID: %03d\tArrival: %03d\tCodesize: %03d\n",
               0, cpus[i].id, idle->pid, idle->arrival_time, idle->code_bytes);

        if (cpus[i].curr == NULL) {
            cpus[i].curr = idle;
            idle->op_remain = idle->operations[0].len;
            cpus[i].last_pid = idle->pid;
        } else {
            list_add_tail(&idle->ready, &cpus[i].rq);
        }
    }
}

/* 런타임 arrival 처리 — arrival_time <= clock 인 프로세스들을
 *   load balancing (ready queue remain 만 비교) 으로 ready queue 에 삽입.
 *   CS 진행 중인 CPU 는 후보에서 제외.
 *   둘 다 CS 중이면 이번 clock 에서는 로드하지 않고 job queue 에 남겨둔다
 *   → 다음 clock 에 CS 가 끝난 CPU 로 지연 로드된다. */
static void arrival_load(struct list_head *jq, cpu_t cpus[], int clock) {
    process *p, *n;
    list_for_each_entry_safe(p, n, jq, job) {
        if (p->arrival_time > clock) continue;

        int best = -1, best_r = 0;
        for (int i = 0; i < N_CPU; i++) {
            if (cpus[i].cs_timer > 0) continue;        /* CS busy → 불가 */
            int r = rq_remain(&cpus[i].rq);
            if (best == -1 || r < best_r) { best = i; best_r = r; }
        }
        if (best == -1) continue;                      /* 두 CPU 모두 CS 중 */

        list_del(&p->job);
        INIT_LIST_HEAD(&p->job);
        list_add_tail(&p->ready, &cpus[best].rq);

        printf("%04d CPU%d: Loaded PID: %03d\tArrival: %03d\tCodesize: %03d\n",
               clock, cpus[best].id, p->pid, p->arrival_time, p->code_bytes);

        /* 대상 CPU 가 idle 을 실행중이었다면 idle 을 ready queue 로 되돌리고
         *   curr 를 비워서 다음 phase 에서 CS 가 트리거되도록 한다. */
        if (cpus[best].curr && cpus[best].curr->pid == IDLE_PID) {
            process *idle = cpus[best].curr;
            cpus[best].curr = NULL;
            list_add_tail(&idle->ready, &cpus[best].rq);
            /* last_pid 는 IDLE_PID 그대로 유지 → "Switched from 100" 으로 출력 */
        }
    }
}

/* ============================================================
 *  Context Switching
 * ============================================================ */

/* 직전 clock 에서 CS 가 끝난 CPU 를 마무리한다.
 *   - curr <- next_proc
 *   - "Switched" 출력
 *   - 새 curr 의 op_remain 을 첫 op 길이로 초기화 */
static void finalize_cs(cpu_t cpus[], int clock) {
    for (int i = 0; i < N_CPU; i++) {
        if (!cpus[i].cs_finalize) continue;

        process *np = cpus[i].next_proc;
        cpus[i].next_proc = NULL;
        cpus[i].curr      = np;

        printf("%04d CPU%d: Switched\tfrom: %03d\tto: %03d\n",
               clock, cpus[i].id, cpus[i].last_pid, np->pid);

        cpus[i].last_pid   = np->pid;
        np->op_remain      = np->operations[np->pc].len;
        cpus[i].io_printed = 0;
        cpus[i].cs_finalize = 0;
    }
}

/* curr 가 비어있고 CS 가 진행중이 아닌 CPU 는 ready queue 에서
 *   다음 실행 프로세스를 골라 CS 를 시작한다. real 이 idle 보다 우선. */
static void trigger_cs(cpu_t cpus[]) {
    for (int i = 0; i < N_CPU; i++) {
        if (cpus[i].cs_timer > 0) continue;
        if (cpus[i].curr != NULL) continue;

        process *np = first_real(&cpus[i].rq);
        if (!np) np = first_idle(&cpus[i].rq);
        if (!np) continue;                 /* 이 일은 일반적으로 발생하지 않음 */

        list_del(&np->ready);
        INIT_LIST_HEAD(&np->ready);

        cpus[i].next_proc = np;
        cpus[i].cs_timer  = CS_CLOCKS;
    }
}

/* ============================================================
 *  Operation processing (한 clock 씩 소비)
 * ============================================================ */
static void tick(cpu_t cpus[], int clock) {
    for (int i = 0; i < N_CPU; i++) {
        cpu_t *c = &cpus[i];

        /* CS 진행 중 — CPU 는 busy (idle clock 증가) */
        if (c->cs_timer > 0) {
            c->idle_clocks++;
            c->cs_timer--;
            if (c->cs_timer == 0) c->cs_finalize = 1;
            continue;
        }

        process *p = c->curr;
        if (!p) { c->idle_clocks++; continue; }      /* 이상 상황 방어 */

        code *curop = &p->operations[p->pc];

        /* IO op 시작 시 1회 출력 (출력 순서 4번: IO START) */
        if (curop->op == OP_IO && !c->io_printed) {
            printf("%04d CPU%d: OP_IO START len: %03d ends at: %04d\n",
                   clock, c->id, curop->len, clock + curop->len);
            c->io_printed = 1;
        }

        /* 시간 통계 */
        if (curop->op == OP_CPU && p->pid != IDLE_PID) c->util_clocks++;
        else                                           c->idle_clocks++;

        /* op 에서 1 clock 소비 */
        p->op_remain--;

        if (p->op_remain > 0) continue;

        /* 현재 op 종료 */
        if (p->pid == IDLE_PID) {
            /* idle 은 같은 op 을 계속 반복 */
            p->op_remain = curop->len;
            continue;
        }

        /* real process: PC 전진 */
        p->pc++;
        if (p->pc >= p->code_bytes / 2) {
            /* 모든 op 종료 → 프로세스 종료 */
            c->last_pid = p->pid;           /* 다음 CS 에서 "from: X" 로 사용 */
            free(p->operations);
            free(p);
            c->curr = NULL;
        } else {
            p->op_remain   = p->operations[p->pc].len;
            c->io_printed  = 0;
        }
    }
}

/* ============================================================
 *  정리
 * ============================================================ */
static void cleanup(struct list_head *jq, cpu_t cpus[]) {
    process *p, *n;

    for (int i = 0; i < N_CPU; i++) {
        list_for_each_entry_safe(p, n, &cpus[i].rq, ready) {
            list_del(&p->ready);
            free(p->operations);
            free(p);
        }
        if (cpus[i].curr) {
            free(cpus[i].curr->operations);
            free(cpus[i].curr);
            cpus[i].curr = NULL;
        }
        if (cpus[i].next_proc) {
            free(cpus[i].next_proc->operations);
            free(cpus[i].next_proc);
            cpus[i].next_proc = NULL;
        }
    }
    list_for_each_entry_safe(p, n, jq, job) {
        list_del(&p->job);
        free(p->operations);
        free(p);
    }
}

/* ============================================================
 *  main
 * ============================================================ */
int main(void) {
    LIST_HEAD(job_q);

    cpu_t cpus[N_CPU];
    for (int i = 0; i < N_CPU; i++) {
        cpus[i].id          = i + 1;
        INIT_LIST_HEAD(&cpus[i].rq);
        cpus[i].curr        = NULL;
        cpus[i].next_proc   = NULL;
        cpus[i].cs_timer    = 0;
        cpus[i].cs_finalize = 0;
        cpus[i].last_pid    = IDLE_PID;
        cpus[i].io_printed  = 0;
        cpus[i].idle_clocks = 0;
        cpus[i].util_clocks = 0;
    }

    /* 1. 바이너리 파일에서 프로세스 tuple 들을 모두 읽어 job queue 에 적재 */
    while (1) {
        process *p = (process *)calloc(1, sizeof(process));
        if (fread(&p->pid, sizeof(int), 1, stdin) != 1) { free(p); break; }
        if (fread(&p->arrival_time, sizeof(int), 1, stdin) != 1) { free(p); break; }
        if (fread(&p->code_bytes,   sizeof(int), 1, stdin) != 1) { free(p); break; }

        int nops = p->code_bytes / 2;
        if (nops > 0) {
            p->operations = (code *)calloc(nops, sizeof(code));
            for (int i = 0; i < nops; i++) {
                if (fread(&p->operations[i].op,  1, 1, stdin) != 1) break;
                if (fread(&p->operations[i].len, 1, 1, stdin) != 1) break;
            }
        }
        p->pc        = 0;
        p->op_remain = 0;
        INIT_LIST_HEAD(&p->job);
        INIT_LIST_HEAD(&p->ready);
        INIT_LIST_HEAD(&p->wait);
        list_add_tail(&p->job, &job_q);
    }

    /* 2. 초기 로드 (clock == 0) */
    initial_load(&job_q, cpus);

    /* 3. 메인 시뮬레이션 루프.
     *    출력 순서: (1) Migration 종료 — 2-2에는 없음
     *               (2) Context Switching 종료
     *               (3) 프로세스 로드
     *               (4) IO 시작 */
    int clock = 0;
    while (any_real_alive(&job_q, cpus)) {
        finalize_cs(cpus, clock);   /* (2) Switched 출력 */
        arrival_load(&job_q, cpus, clock); /* (3) Loaded 출력 */
        trigger_cs(cpus);           /* curr 비어있는 CPU 의 CS 시작 */
        tick(cpus, clock);          /* (4) IO START 출력 + 1 clock 소비 */
        clock++;
    }

    /* 4. Final report */
    double u1 = (clock > 0) ? ((double)cpus[0].util_clocks / clock) * 100.0 : 0.0;
    double u2 = (clock > 0) ? ((double)cpus[1].util_clocks / clock) * 100.0 : 0.0;
    double ut = (clock > 0)
                ? ((double)(cpus[0].util_clocks + cpus[1].util_clocks) / (clock * N_CPU)) * 100.0
                : 0.0;

    printf("*** TOTAL CLOCKS: %04d CPU1 IDLE: %04d CPU2 IDLE: %04d "
           "CPU1 UTIL: %2.2f%% CPU2 UTIL: %2.2f%% TOTAL UTIL: %2.2f%%\n",
           clock, cpus[0].idle_clocks, cpus[1].idle_clocks, u1, u2, ut);

    cleanup(&job_q, cpus);
    return 0;
}
