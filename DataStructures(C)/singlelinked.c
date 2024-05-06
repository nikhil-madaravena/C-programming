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

//adding a node at the end
void append(int data){
    struct node *newnode = createnode(data);
    if(head==NULL){
        head=newnode;
        return ;
    }
    struct node *temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
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

// delete at first
void deletefirst(){
    struct node *temp;
    temp=head;
    head=head->next;
    printf("Deleted node data %d \n ",temp->data);
    free(temp);
    
}

// delete at end
void deleteend(){
    struct node *temp, *prev;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("Deleetd node data is %d \n ",temp->data);
    free(temp);
}

// delete at any with pos
void deleteanypos(int index){
    struct node *temp,*prev;
    temp=head;
    int i=1;
    while(temp->next!= NULL){
        if(i==index){
            break;
        }
        i++;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    printf("Deleted element is %d\n",temp->data);
    free(temp);
}

//delete at any with data
void deleteanydata(int data){
    struct node *temp,*prev;
    temp=head;
    while(temp->data != data ){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    printf("Deleetd node data is %d\n",temp->data);
    free(temp);
}

// displaying elements 
void display(){
    struct node *temp;
    temp=head;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}

int main(){
    int choice,data,index;
    while(choice!=9){
        printf("\n 1.Insert end  \n 2.Insert first \n 3. Insert any \n 4. Delete first \n 5. Delete end \n 6. Delete at any pos \n 7. delete at any with given data as input \n 8. display \n 9. exit \n ");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert : ");
            scanf("%d",&data);
            append(data);
            break;
        case 2:
            printf("Enter data to insert : ");
            scanf("%d",&data);
            insertfirst(data);
            break;
        case 3:
            printf("Enter data to insert : ");
            scanf("%d",&data);
            int index;
            printf("Enter position : ");
            scanf("%d",&index);
            insertany(data,index);
            break;
        case 4:
            deletefirst();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            printf("Enter position : ");
            scanf("%d",&index);
            deleteanypos(index);
            break;
        case 7:
            printf("Original Linked list : ");
            display();
            printf("Enter data u wanted to delete: ");
            scanf("%d",&data);
            deleteanydata(data);
            break;
        case 8:
            display();
            break;
        default:
        printf("Enter valid input !!!!");
            break;
        }
    }
}