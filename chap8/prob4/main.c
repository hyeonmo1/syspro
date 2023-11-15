#include <stdio.h>
#include <stdlib.h>
static void exit_handler1(void),
            exit_handler2(void);

int main(void)
{
    if(atexit(exit_handler1) != 0)
        perror("exit_handler1 NO");
     if(atexit(exit_handler2) != 0)
           perror("exit_handler2 NO");
     printf("main exit \n");
     exit(0);
}
static void exit_handler1(void)
{
    printf("first exit \n");
}

static void exit_handler2(void)
{
   printf("second exit \n");
}

