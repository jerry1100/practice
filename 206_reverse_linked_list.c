/*
Reverse a singly linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode* head);
// Given: the head of a linked list
// Return: the head of the reversed linked list

int main() {
    struct ListNode nodes[4]; // test case using 4 nodes

    // Initialize linked list of size 4
    printf("Initial list: \n");
    int i;
    for (i = 0; i < 4; i++) {
        nodes[i].val = i;
        nodes[i].next = (i < 3) ? &nodes[i+1] : NULL;
        printf("Val: %d, Current: %p, Next: %p\n", nodes[i].val, &nodes[i], 
            &nodes[i+1]);
    }

    // Reverse list
    printf("\nReversed list: \n");
    struct ListNode *revNodes = reverseList(&nodes[0]);
    while (revNodes != NULL) {
        printf("Val: %d, Current: %p, Next: %p\n", revNodes->val, revNodes, 
            revNodes->next);
        revNodes = revNodes->next;
    }
}

struct ListNode *reverseList(struct ListNode* head) {
    struct ListNode *prevNode = NULL;
    struct ListNode *nextNode;

    // Flip each node in the list
    while (head != NULL) {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }

    return prevNode;
}
