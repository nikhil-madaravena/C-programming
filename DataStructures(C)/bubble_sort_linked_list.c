#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node * createnode(int data){
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
}

void append(int data){
    struct node* newnode,*temp;
    newnode=createnode(data);
    temp=head;
    if(head==NULL){
        head=newnode;
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}

void swapData(struct node* a, struct node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort() {
    int swapped; 
    struct node *temp, *curr = NULL;

    if (head == NULL) {
        return;
    }
    
    do {
        swapped = 0;
        temp = head;

        while (temp->next != curr) {
            if (temp->data > temp->next->data) {
                swapData(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        curr = temp;
    } while (swapped);
}

void display(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n,data;
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        append(data);
    }
    printf("List before Sorting : ");
    display();
    bubbleSort();
    printf("\nList after Selection Sort: ");
    display();
}