#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <szieof.h>

int main()
{
    int count = 0, id;
    char name[20];
    struct student *p, *head = NULL;

    printf("studentnumber name\n");
	    while (scanf("%d %s", &id, name) == 2)  {
        p = (struct student *) malloc(sizeof(struct student));
        if (p == NULL) {
            perror("malloc");
            exit(1);
        }
        p->id = id;
        strcpy(p->name, name);
        p->next = head;
        head = p;
    }
		    printf("\n* *\n");
    p = head;
    while (p != NULL)  {
        count++;
        printf("number: %d name:  %s \n", p->id,  p->name);
        p = p->next;
    }
    printf("%d .\n", count);
    exit(0);
}

