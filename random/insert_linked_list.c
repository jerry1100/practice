// Insert into linked list in ascending order

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    struct ListNode *next;
    int val;
} ListNode;


// Given pointer to head of list, display the list
void display(ListNode *head);

// Given double pointer to head of list, inserts num in list in ascending
// order
void insert(ListNode **head_ptr, int num);

int main() {
    ListNode *head = NULL;
    int num;

    printf("Enter a number to insert (EOF to quit): ");
    while (scanf("%d", &num) != EOF) {
        insert(&head, num);
        display(head);
        printf("Enter a number to insert (EOF to quit): ");
    }

    printf("\nGoodbye...\n");
}


void display(ListNode *head) {
    printf("List: {");
    while (head != NULL) {
        printf(" %d ", head->val);
        head = head->next;
    }
    printf("}\n");
}

void insert(ListNode **head_ptr, int num) {
    ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
    new_node->val = num;

    // Update head if new node is before current head
    if (*head_ptr == NULL || num < (*head_ptr)->val) {
        new_node->next = *head_ptr;
        *head_ptr = new_node;
    } else {
        // Find where new node belongs
        ListNode *node_ptr = *head_ptr;
        while (node_ptr->next != NULL && node_ptr->next->val < num) {
            node_ptr = node_ptr->next;
        }
        
        new_node->next = node_ptr->next;
        node_ptr->next = new_node;
    }
}
