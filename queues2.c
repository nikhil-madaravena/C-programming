#include<stdio.h>
int f=-1,r=-1;
int queue[100];

void enqueue(int el){  
    
    if(f==-1 && r==-1)
        f=0;

    if(r==100&&f!=0)
        r=0;
        queue[++r]=el;
    
}

int dequeue(){
    if(f==-1 && r==-1){
        printf("queue is empty");
        return -1;
    }
    int del=queue[f++];
    return del;
}

void display(){
    for(int i=f;i<=r;i++){
        printf("%d ",queue[i]);
    }
}

int main(){
    printf("Enter the element you want to enqueue: ");
    int el;
    scanf("%d",&el);
    enqueue(el);

    printf("Enter the element you want to enqueue: ");
    scanf("%d",&el);
    enqueue(el);

    printf("Enter the element you want to enqueue: ");
    scanf("%d",&el);
    enqueue(el);

    display();
    printf("\n");

    printf("Dequeued %d\n",dequeue());
    printf("Dequeued %d\n",dequeue());

}