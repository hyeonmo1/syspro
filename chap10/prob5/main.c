#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("Added to queue: %d\n", data);
}
int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int data = (*head)->data;
    struct node *temp = *head;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(temp);

    printf("Deleted from queue: %d\n", data);
    
    return data;
}

void printQueue(struct node *head) {
    printf("Queue: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;

    addq(&head, &tail, 10);
    addq(&head, &tail, 20);
    addq(&head, &tail, 30);

    printQueue(head);
    int deletedValue = delete(&head, &tail);
    printQueue(head);

    return 0;
}
