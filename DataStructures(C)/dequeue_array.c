#include<stdio.h>
#define MAX 100
int dqueue[MAX];
int rear = -1;
int front = -1;
void enqueueRear(int data){
    if(front == 0 && rear == MAX-1){
        printf("Double ended queue overflow\n");
        return;
    }
    dqueue[++rear]=data;
    if(front == -1)
        front = 0;
}

void enqueueFront(int data){
    if(front == 0 && rear == MAX-1){
        printf("Double ended queue overflow\n");
        return;
    }
    if((front == 0 || front == -1) && rear != MAX-1){
        if(front == -1){
            front = 0;
        }
        for(int i=rear;i>=front;i--){
            dqueue[i+1]=dqueue[i];
        }
        rear++;
        dqueue[front]=data;
    }else if(rear != MAX-1 && (front != -1 && front !=0)){
        dqueue[--front]=data;
    }
}

void dequeueRear(){
    if(rear ==-1 && front == -1){
        printf("Double ended queue underflow\n");
        return;
    }
    printf("Deleted element: %d\n",dqueue[rear--]);
}

void dequeueFront(){
    if(rear ==-1 && front == -1){
        printf("Double ended queue underflow\n");
        return;
    }
    printf("Deleted element: %d\n",dqueue[front++]);
}


void display(){
    if(front == -1 && rear == -1)
        printf("Double ended queue empty\n");
    else{
        printf("\n\nElements in the double ended queue:\n");
        for(int i=front;i<=rear;i++){
            printf("%d ",dqueue[i]);
        }
        printf("\n\n");
    }
}

int main(){
    int choice,data;
    while(1){
        printf("1. EnqueueFront\n2. EnqueueRear\n3. DequeueFront\n4. DequeueRear\n5. Display\n6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d",&data);
            enqueueFront(data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d",&data);
            enqueueRear(data);
            break;
        case 3:
            dequeueFront();
            break;
        case 4:
            dequeueRear();
            break;
        case 5:
            display();
            break;
        case 6:
            return 1;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}