#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head=NULL,*tail=NULL;  

struct node * createnode(int data){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->next=NULL; 
    newnode->data=data;
    return newnode;
}

void append(int data){     //insert last
    struct node *newnode=createnode(data);
    if(head==NULL) {
        head=newnode;
        tail=newnode;     
        return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;        
}

void insertFirst(int data){ //insert at begining
    struct node *newnode=createnode(data);
    if(head==NULL) {
        head=newnode;
        tail=newnode;
        return ;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void deleteFirst(){
    struct node *temp;
    temp=head;
    if(head==NULL) {
        printf("List is empty\n");
        return;
    }
    head=head->next;
    head->prev=NULL;
    free(temp);                  /* Free the memory occupied by the deleted node */
}

void deleteLast(){
    if(head == NULL){                /* If list is already empty then there's nothing to delete.*/
        printf("The list is empty.\n");
        return;
    }
    struct node *temp;
    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}

void display(){
    int flag=0;
    struct node *temp=NULL;
    printf("Select from which side to display the list \n1.Front 2.Back\n");
    printf("Enter choice: ");
    scanf("%d",&flag);
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(flag==1){
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }else if(flag==2){
        temp=tail;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp=temp->prev;
        }
        printf("\n");
    }
}

int main(){
    int  choice=0,data;
    while(choice!=6){
        printf("1.Append\n2.insertFirst\n3.deleteFirst\n4.deleteLast\n5.display\n6.Exit\n");
        printf("Enter your choice : ");
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
                insertFirst(data);
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
            default:
                printf("Please enter a valid choice !!\n");
        }
    }
}