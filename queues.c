#include <stdio.h>
#define max 100
int front=-1,rear=-1;
int queue[max];

void enqueue(int val){
    if(front == -1 && rear == -1){
    front = 0;
    rear=0;
    queue[rear]=val;
    }
    else{
        queue[++rear]=val;
    }
}

int dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow");
    }
    else{
        return queue[front++];
    }
}

void display(){
    for(int i=front; i<=rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    printf("\n dequeued %d\n", dequeue());
    display();
}