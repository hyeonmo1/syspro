#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler(int signo);

int main() {
    struct sigaction sa;

    sa.sa_handler = alarmHandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);


    alarm(5);

    printf("무한 루프 \n");

    while (1) {
        sleep(1);
        printf("1초 경과 \n");
    }

    printf("실행되지 않음 \n");
}

void alarmHandler(int signo) {
    printf("일어나세요\n");
    exit(0);
}
