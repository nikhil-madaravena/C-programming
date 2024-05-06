#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, int item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Error: stack is full\n");
    } else {
        s->top++;
        s->items[s->top] = item;
    }
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: stack is empty\n");
        return -1;
    } else {
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

void move(Stack *source, Stack *target) {
    int item = pop(source);
    push(target, item);
}

void hanoi(Stack *source, Stack *target, Stack *aux, int n) {
    if (n == 1) {
    	
        move(source, target);
         
    } else {
    	
        hanoi(source, aux, target, n - 1);
        
        move(source, target);
        
        hanoi(aux, target, source, n - 1);
    }
}

int main() {
    Stack source, target, aux;
    source.top = -1;
    target.top = -1;
    aux.top = -1;

    int n,i;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    for (i = n; i >= 1; i--) {
        push(&source, i);
    }

    hanoi(&source, &target, &aux, n);

    printf("\nTower of Hanoi solution:\n");
    while (target.top != -1) {
        printf("%d ", pop(&target));
    }
    printf("\n");

    return 0;
}

