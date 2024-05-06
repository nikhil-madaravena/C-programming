#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *head1=NULL,*head2=NULL;
struct node * createnode(int data){
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
}

void append(int data,int list){
    struct node* newnode,*temp;
    newnode=createnode(data);
    if(list==1)
    temp=head1;
    else if(list==2)
    temp=head2;
    if(temp==NULL && list==1){
        head1=newnode;
        return;
    }
    if(temp==NULL && list==2){
        head2=newnode;
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}

void display(int list){
    struct node* temp;
    if(list==1)
    temp=head1;
    else if(list==2)
    temp=head2;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void zig_zag_merge() {
    if (head1 == NULL || head2==NULL) {
        return; // One or both lists are empty
    }
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *curr1, *curr2;
    while (temp1!=NULL && temp2!=NULL) {
        curr1 = temp1->next;
        curr2 = temp2->next;
        temp1->next = temp2;
        temp2->next = curr1;
        temp1 = curr1;
        temp2 = curr2;
    }
    head1 = head1;
    head2 = NULL;
}

int main(){
    int m,data;
    printf("Enter the size of the list 1 : ");
    scanf("%d",&m);
    printf("Enter data for the list 1 : \n");
    for(int i=1; i<=m; i++){
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        append(data,1);
    }

    int n;
    printf("Enter the size of the list 2 : ");
    scanf("%d",&n);
    printf("Enter data for the list 2 : \n");
    for(int i=1; i<=n; i++ ) {
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        append(data,2);
    }
    printf("Lists before merging :\n");
    printf("List 1: ");
    display(1);
    printf("List 2: ");
    display(2);
    zig_zag_merge();
    printf("List after zig zag merging : \n");
    display(1);
    }