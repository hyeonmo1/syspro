#include<sys/types.h>
#include<sys/wait.h>
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *statloc, int options);

int main()
{
    int pid, child, status;
    printf("[%d] parents process start \n", getpid());
    pid = fork();
    if(pid == 0){
        printf("[%d] brother process start\n", getpid());
        exit(1);
    }
    child = wait(&status);
    printf("[%d] brother process %d exit \n", getpid(), child);
    printf("\exit code %d\n", status >> 8);
}
