#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node * createNode(int data){
    struct node* newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev=NULL;
    newnode->next=NULL;
}

void append(int data){
    struct node* newnode = createNode(data);
    if(head==NULL){
        head=newnode;
        head->next=head;
        head->prev=head;
        return;
    }
    struct node *temp,*prev;
}

void insertLast(int data){
    struct node *newnode=createNode(data);
    if(head == NULL) {
        head=newnode;
        head->next=head;
        return;
    }
    struct node *temp;
    temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    head=newnode;
}

void deleteFirst(){
    if(head == NULL){
        printf("List is empty\n"); 
        return; 
    }
    struct node *temp;
    temp=head; 
    while (temp->next != head) 
        temp = temp->next;
    temp->next=head->next;
    temp=head;
    head=head->next;
    free(temp);
}

void deleteLast(){
    if(head == NULL){
        printf("List is empty\n"); 
        return; 
    }
    struct node *prev,*temp;
    temp=head;
    while(temp-> next != head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    free(temp);
}

void display(){
    struct node *temp;
    temp=head;
    if(temp==NULL){
        printf("The list is empty \n");
        return;
    }
    printf("\nElements in the list are : ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

int main(){
    int choice=0,data;
    while(choice!=6){
        printf("1.Append\n2.insertFirst\n3.deleteFirst\n4.deleteLast\n5.display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d",&data);
                append(data);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d",&data);
                insertLast(data);
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                printf("Enter a valid Choice!! \n");
        }
    }
}