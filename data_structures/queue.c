/*
Queue implementation using linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

void init_queue(Queue *queue);
// Given: pointer to a queue
// Initializes the queue

void enqueue(Queue *queue, int num);
// Given: pointer to a queue and the integer to be added
// Adds integer to the end of queue

void dequeue(Queue *queue);
// Given: pointer to a queue
// Removes the head of the queue

void print_queue(const Queue *queue);
// Given: pointer to a queue
// Prints out the contents of the queue

int main() {
    Queue queue;
    init_queue(&queue);

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
                enqueue(&queue, num);
                print_queue(&queue);
                break;
            }
            case 'd':
                dequeue(&queue);
                print_queue(&queue);
                break;
            case 'q': return 0;
            default:
                printf("Invalid option\n");
        }
    }
}

void init_queue(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

void enqueue(Queue *queue, int num) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->val = num;
    new_node->next = NULL;

    if (queue->head == NULL) { // queue is empty so set head and tail
        queue->head = new_node;
        queue->tail = new_node;
    } else { // queue is not empty so add node and update tail
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

void dequeue(Queue *queue) {
    if (queue->head != NULL) {
        Node *tmp = queue->head->next;
        free(queue->head);
        queue->head = tmp;
    }
}

void print_queue(const Queue *queue) {
    Node *tmp = queue -> head;
    printf("Queue: {");
    while (tmp != NULL) {
        printf(" %d", tmp->val);
        tmp = tmp->next;
    }
    printf(" }\n");
}
