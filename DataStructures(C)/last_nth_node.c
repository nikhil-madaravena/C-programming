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

void display(int n,int pos){
    struct node* temp=head;
    for(int i=0;i<n-pos;i++){
        temp=temp->next;
}
printf("The node at position %d from the end of the list is %d\n",pos,temp->data);
return ;
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
    int pos;
    printf("Enter the position to display from the end of the list: ");
    scanf("%d",&pos);
    display(n,pos);
}