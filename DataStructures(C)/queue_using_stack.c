#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Structure for stack
typedef struct {
    int items[SIZE];
    int top;
} Stack;

// Initialize stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == SIZE - 1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push item onto stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = value;
}

// Pop item from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Queue structure using two stacks
typedef struct {
    Stack s1, s2;
} Queue;

// Initialize queue
void initializeQueue(Queue *q) {
    initialize(&q->s1);
    initialize(&q->s2);
}

// Enqueue item into queue
void enqueue(Queue *q, int value) {
    if (isFull(&q->s1)) {
        printf("Queue is full\n");
        return;
    }

    // Move all items from s1 to s2
    while (!isEmpty(&q->s1)) {
        push(&q->s2, pop(&q->s1));
    }

    // Push new item onto s1
    push(&q->s1, value);

    // Move all items back to s1
    while (!isEmpty(&q->s2)) {
        push(&q->s1, pop(&q->s2));
    }
}

// Dequeue item from queue
int dequeue(Queue *q) {
    if (isEmpty(&q->s1)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return pop(&q->s1);
}

int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}