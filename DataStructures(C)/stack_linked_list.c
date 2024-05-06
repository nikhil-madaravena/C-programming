#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *top=NULL;
struct node *createnode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void push(int data){
    struct node *newnode = createnode(data);
    if(top==NULL){
        top=newnode;
        return;
    }
    newnode->next=top;
    top=newnode;
}

void pop(){
    if(top == NULL) {
        printf("Stack Underflow\n");
        return ;
    }
    struct node* temp = top;
    top=top->next;
    printf("popped : %d\n",temp->data);
    free(temp);
}

void peek(){
    if(top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Top element is %d \n",top->data);
    struct node *temp;
    temp=top;
    int i=0;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
    printf("Number of elements in the stack are %d \n",i);
}

void display(){
    struct node* temp;
    temp=top;
    printf("Elements in the stack: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int choice,data;
    while(choice!=5){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter element to push: ");
            scanf("%d",&data);
            push(data);
        }else if(choice == 2){
            pop();
        }else if(choice == 3){
            peek();
        }else if(choice == 4){
            display();
        }else if(choice == 5){
            exit(0);
        }else{
            printf("Invalid Input\n");
        }
    }
}