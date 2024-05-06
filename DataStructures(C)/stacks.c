#include<stdio.h>
#define max 100
int top=-1;
int stack[max];

void push(int val){
    if(top==max-1)
    printf("overflow");
    else{
        stack[++top]=val;
    }
}

int pop(){
    if(top==-1)
    printf("Underflow");
    else{
        int n;
        n=stack[top--];
        return n;
    }
}

void peek(){
    printf("top : %d, stack[top] : %d\n", top,stack[top]);
}

void display(){
    int i;
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);

    printf("poped : %d\n",pop());
    peek();

    display();
}