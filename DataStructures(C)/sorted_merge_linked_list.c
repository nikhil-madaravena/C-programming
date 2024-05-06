#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}


struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* mergedList = NULL;

    if (list1->data <= list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }

    struct Node* current = mergedList;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList;
}

// Function to display elements of a linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int m,data;
    printf("Enter the size of the list 1 : ");
    scanf("%d",&m);
    printf("Enter data for the list 1 : \n");
    for(int i=1; i<=m; i++){
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        insertAtEnd(&list1,data);
    }

    int n;
    printf("Enter the size of the list 2 : ");
    scanf("%d",&n);
    printf("Enter data for the list 2 : \n");
    for(int i=1; i<=n; i++ ) {
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        insertAtEnd(&list2,data);
    }
    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    // Merge and display the merged list
    struct Node* mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    displayList(mergedList);

    return 0;
}
