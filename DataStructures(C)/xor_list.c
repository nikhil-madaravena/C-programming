#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Node structure for XOR linked list
typedef struct Node {
    int data;
    struct Node* xor_ptr; // XOR of previous and next node addresses
} Node;

// Function to XOR two pointers
Node* xorPtr(Node* a, Node* b) {
    return (Node*)((uintptr_t)a ^ (uintptr_t)b);
} 

// Function to insert a node at the beginning of the XOR linked list
void insert(Node** head_ref, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    // XOR of new node's address and next node's address (which is NULL initially)
    new_node->xor_ptr = xorPtr(NULL, *head_ref);

    if (*head_ref != NULL) {
        // XOR of next node's XORed pointer and new node's address
        Node* next = xorPtr((*head_ref)->xor_ptr, NULL);
        (*head_ref)->xor_ptr = xorPtr(new_node, next);
    }

    // Update the head to point to the new node
    *head_ref = new_node;
}

// Function to traverse the XOR linked list from the beginning
void traverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    printf("XOR Linked List: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        next = xorPtr(prev, curr->xor_ptr);
        prev = curr;
        curr = next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert elements into the XOR linked list
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    // Traverse and print the XOR linked list
    traverse(head);

    return 0;
}
