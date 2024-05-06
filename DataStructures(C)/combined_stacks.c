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

void combine(Stack *s1, Stack *s2) {
    while (s2->top != -1) {
        int item = pop(s2);
        push(s1, item);
    }
}

int main() {
    Stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);

    push(&s2, 4);
    push(&s2, 5);
    push(&s2, 6);

    combine(&s1, &s2);

    while (s1.top != -1) {
        printf("%d ", pop(&s1));
    }
    printf("\n");

    return 0;
}

