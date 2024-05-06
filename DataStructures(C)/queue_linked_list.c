#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *front,*back;

struct node *createnode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void enqueue(int data){
    struct node *newnode = createnode(data);
    if(front == NULL) {
        front = back = newnode;
    }
    back->next=newnode;
    back = newnode;
}

void dequeue(){
    struct node *temp;
    temp=front;
    if(front==NULL) {
        printf("Queue is empty\n");
        return;
    }
    front=front->next;
    printf("Dequeued : %d\n",temp->data);
    free(temp);
}

void display(){
    struct node *temp;
    temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int choice,data;
    while(choice!=4){
        printf("\nMenu:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid Input\n");
        }
    }
}