#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void intHandler();

int main( )
{
   signal(SIGINT,intHandler);
   while (1)
      pause();
   printf("not exit \n");
}
void intHandler(int signo)
{
   printf("interlubt signal \n"); 
   printf("signal nuber: %d\n", signo);
   exit(0);
}

