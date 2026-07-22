#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 과제에서 제공된 Linux List Library 헤더

// 동작(Operation)을 저장할 튜플 구조체 (1 튜플 = 2 Bytes) [1]
typedef struct {
    unsigned char op;  // 작업 종류 (예: 00=CPU, 01=IO)
    unsigned char len; // 동작 소요 시간
} code;

// 프로세스 정보를 담을 뼈대 구조체 [1, 3]
typedef struct {
    int pid;              // 프로세스 ID
    int arrival_time;     // 도착 시간
    int code_bytes;       // 코드 길이 (바이트 단위)
    code *operations;     // code tuples가 동적 할당되어 저장될 위치
    
    // 큐 연결을 위한 list_head 필드
    struct list_head job, ready, wait;
} process;

int main() {
    // 1. job_q 전체 리스트의 머리(Head) 초기화 [4]
    LIST_HEAD(job_q);

    // 2. 표준 입력(stdin)으로부터 이진 파일 읽어오기
    while (1) {
        // 프로세스 구조체 동적 할당
        process *p = (process *)malloc(sizeof(process));
        
        // 파일의 끝(EOF)에 도달하면 루프 종료
        // pid를 4바이트(int) 크기로 1개 읽어옴
        if (fread(&p->pid, sizeof(int), 1, stdin) != 1) {
            free(p);
            break;
        }
        
        // 도착 시간과 코드 길이 마저 읽기 (고정 크기 12바이트) [1]
        fread(&p->arrival_time, sizeof(int), 1, stdin);
        fread(&p->code_bytes, sizeof(int), 1, stdin);

        // 3. Code Tuple 동적 할당 및 읽기 (가변 크기) [1]
        // 1개의 튜플은 2바이트(op 1바이트 + len 1바이트)이므로 반으로 나눔
        int num_tuples = p->code_bytes / 2;
        p->operations = (code *)malloc(sizeof(code) * num_tuples);
        
        for (int i = 0; i < num_tuples; i++) {
            fread(&p->operations[i].op, sizeof(unsigned char), 1, stdin);
            fread(&p->operations[i].len, sizeof(unsigned char), 1, stdin);
        }

        // list_head 요소 초기화 (선택적이지만 안전함을 위해)
        INIT_LIST_HEAD(&p->job);
        INIT_LIST_HEAD(&p->ready);
        INIT_LIST_HEAD(&p->wait);

        // 4. job_q의 꼬리(tail)에 새로운 프로세스 정보 삽입 [2, 4]
        list_add_tail(&p->job, &job_q);
    }

    // 5. 로드된 프로세스 정보를 역순으로 출력 [2]
    process *cur;
    
    // list_for_each_entry_reverse를 사용하여 역순 순회 [4]
    list_for_each_entry_reverse(cur, &job_q, job) {
        // 프로세스 기본 정보 출력 (Litmus 형식에 맞춤)
        printf("PID: %03d\tARRIVAL: %03d\tCODESIZE: %03d\n", cur->pid, cur->arrival_time, cur->code_bytes);
        
        // 동적 할당된 Code Tuples 순서대로 출력
        int num_tuples = cur->code_bytes / 2;
        for (int i = 0; i < num_tuples; i++) {
            // op와 len은 unsigned char이므로 정수 형태로 출력
            printf("%d %d\n", cur->operations[i].op, cur->operations[i].len);
        }
    }

    // 메모리 해제 로직 (프로그램 종료 전 할당 해제)
    process *next;
    list_for_each_entry_safe(cur, next, &job_q, job) {
        list_del(&cur->job);
        free(cur->operations); // 내부 코드 배열 먼저 해제
        free(cur);             // 프로세스 구조체 해제
    }

    return 0;
}
