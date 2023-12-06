#include <stdio.h>
#include <signal.h>
void alarmHandler();

int main()
{
	signal(SIGALRM, alarmHandler);
    alarm(5);
	printf("roof \n");
	while(1);{
	printf("1 second \n");
	}
	printf("not exit \n");
}

void alarmHandler(int signo)
{
	printf("wake up \n");
	exit(0);
}

