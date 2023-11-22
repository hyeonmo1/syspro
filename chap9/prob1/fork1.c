#include<stdio.h>
#include<unistd.h>

int main()
{
    int pid;
    printf("[%d] proeces start\n", getpid());
    pid = fork();
    printf("[%d] proeces : return %d\n", getpid(), pid);
}

