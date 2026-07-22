#include <stdio.h>
#include <unistd.h>

int main() {
    alarm(5);
    printf("루프 시작\n");
    while (1) {
        sleep(1);
        printf("1초 경과\n");
    }
}