


#include<stdio.h>
#include<unistd.h>
#include<signal.h>

struct sigaction newact;
struct sigaction oldact;
void sigint_handler(int signo);

int main( void)
{
	newact.sa_handler = sigint_handler;
	sigfillset(&newact.sa_mask); 

	sigaction(SIGINT, &newact, &oldact);
	while(1){
		printf("ctrl-c push !\n");
		sleep(1);
	}
}

 void sigint_handler(int signo)
 {
     printf( "%d signal !\n", signo);
     printf( "one more end .\n");
     sigaction(SIGINT, &oldact, NULL);
 }

