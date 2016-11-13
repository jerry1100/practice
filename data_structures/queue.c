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

void print_queue(Node *head);
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
                print_queue(head);
                break;
            }
            case 'd':
                dequeue(&head);
                print_queue(head);
                break;
            case 'q': return 0;
            default:
                printf("Invalid option\n");
        }
    }
}

void enqueue(Node **head, Node **tail, int num) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->val = num;
    new_node->next = NULL;

    if (*head == NULL) { // queue is empty so set head and tail
        *head = new_node;
        *tail = new_node;
    } else { // queue is not empty so add node and update tail
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

void dequeue(Node **head) {
    if (*head != NULL) {
        Node *tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}

void print_queue(Node *head) {
    printf("Queue:");
    while (head != NULL) {
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");
}
