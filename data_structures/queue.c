/*
Queue implementation using linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void enqueue(Node **head, Node **tail, int num);
// Given: double pointers to head and tail of queue, and integer
// Update head and tail and adds new node with value num

void dequeue(Node **head);
// Given: double pointer to head of queue
// Removes head of queue and updates head pointer

void printQueue(Node *head);
// Given: pointers to head and tail of queue
// Prints out the elements in the queue

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    for (;;) {
        printf("\nEnter (e)nqueue, (d)equeue or (q)uit: ");
        char ch;
        scanf("%c", &ch);
        while (getchar() != '\n'); // remove trailing chars in stdin

        switch (ch) {
            case 'e': {
                printf("Enter a number to add: ");
                int num;
                scanf("%d", &num);
                while (getchar() != '\n'); // remove trailing chars in stdin
                enqueue(&head, &tail, num);
                printQueue(head);
                break;
            }
            case 'd':
                dequeue(&head);
                printQueue(head);
                break;
            case 'q': return 0;
            default:
                printf("Invalid option\n");
        }
    }
}

void enqueue(Node **head, Node **tail, int num) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->val = num;
    newNode->next = NULL;

    if (*head == NULL) { // queue is empty so set head and tail
        *head = newNode;
        *tail = newNode;
    } else { // queue is not empty so add node and update tail
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void dequeue(Node **head) {
    if (*head != NULL) {
        Node *tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}

void printQueue(Node *head) {
    printf("Queue:");
    while (head != NULL) {
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");
}
