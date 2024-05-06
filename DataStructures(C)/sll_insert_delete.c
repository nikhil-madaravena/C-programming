#include <stdio.h>
#include <stdlib.h>
struct node{
    int data ;
    struct node *next;
};
struct node *head = NULL ;

// Creating a node 
struct node * createnode(int data){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

//adding at first 
void insertfirst(int data){
    struct node *newnode = createnode(data);
    if(head==NULL){
        head=newnode;
        return ; 
    }
    struct node *temp;
    temp=head;
    newnode->next=temp;
    head=newnode;
}

//adding at any 
void insertany(int data , int index){
    struct node *newnode = createnode(data);
    if(head==NULL){
        head=newnode;
        return ;
    }
    struct node *temp;
    temp=head;
    int i=1;
    while(temp->next!=NULL){
        if(i==index)
        break;
        i++;
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

// displaying elements 
void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}

int main(){
    int choice,data,index;
    while(choice!=4){
        printf("\n 1. Insert first \n 2. Insert any \n 3. display \n 4. exit \n ");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert : ");
            scanf("%d",&data);
            insertfirst(data);
            break;
        case 2:
            printf("Enter data to insert : ");
            scanf("%d",&data);
            int index;
            printf("Enter position : ");
            scanf("%d",&index);
            insertany(data,index);
            break;
        case 3:
            display();
            break;
        default:
        printf("Enter valid input !!!!");
            break;
        }
    }
}