#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = *top;

   *top = newNode;

    printf("Pushed: %d\n", data);
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    int data = (*top)->data;
    struct node *temp = *top;
    *top = (*top)->next;
    free(temp);

    printf("Popped: %d\n", data);
    
    return data;
}
void printStack(struct node *top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    printStack(top);
    int poppedValue = pop(&top);
    printStack(top);

    return 0;
}
