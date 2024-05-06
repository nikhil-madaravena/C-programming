#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the beginning of a linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Function to display elements of a singly linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to perform insertion sort on a singly linked list
void insertionSort(struct Node** head_ref) {
    struct Node *sorted = NULL, *current = *head_ref;

    while (current != NULL) {
        struct Node* nextNode = current->next;

        // Find the position to insert in the sorted list
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* ptr = sorted;
            while (ptr->next != NULL && ptr->next->data < current->data) {
                ptr = ptr->next;
            }
            current->next = ptr->next;
            ptr->next = current;
        }

        current = nextNode;
    }

    // Update head of the linked list
    *head_ref = sorted;
}

int main() {
    struct Node* head = NULL;

int n,data;
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        insertAtBeginning(&head, data);
    }

    printf("Original list: ");
    displayList(head);

    insertionSort(&head);

    printf("Sorted list: ");
    displayList(head);

    return 0;
}