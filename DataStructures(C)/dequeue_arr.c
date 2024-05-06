#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct dequeue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Dequeue;


Dequeue* createDequeue() {
    Dequeue* dequeue = (Dequeue*) malloc(sizeof(Dequeue));
    dequeue->front = -1;
    dequeue->rear = -1;
    return dequeue;
}


int isFull(Dequeue* dequeue) {
    if ((dequeue->front == 0 && dequeue->rear == MAX_SIZE-1) || 
            dequeue->front == dequeue->rear+1) {
        return 1;
    }
    return 0;
}


int isEmpty(Dequeue* dequeue) {
    if (dequeue->front == -1) {
        return 1;
    }
    return 0;
}


void addFront(Dequeue* dequeue, int element) {
    if (isFull(dequeue)) {
        printf("Dequeue is full.\n");
    } else {
        if (dequeue->front == -1) {
            dequeue->front = 0;
            dequeue->rear = 0;
        } else if (dequeue->front == 0) {
            dequeue->front = MAX_SIZE-1;
        } else {
            dequeue->front--;
        }
        dequeue->items[dequeue->front] = element;
        printf("Added %d to the front of dequeue.\n", element);
    }
}


void addRear(Dequeue* dequeue, int element) {
    if (isFull(dequeue)) {
        printf("Dequeue is full.\n");
    } else {
        if (dequeue->front == -1) {
            dequeue->front = 0;
            dequeue->rear = 0;
        } else if (dequeue->rear == MAX_SIZE-1) {
            dequeue->rear = 0;
        } else {
            dequeue->rear++;
        }
        dequeue->items[dequeue->rear] = element;
        printf("Added %d to the rear of dequeue.\n", element);
    }
}


int removeFront(Dequeue* dequeue) {
    int element;
    if (isEmpty(dequeue)) {
        printf("Dequeue is empty.\n");
        return -1;
    } else {
        element = dequeue->items[dequeue->front];
        if (dequeue->front == dequeue->rear) {
            dequeue->front = -1;
            dequeue->rear = -1;
        } else if (dequeue->front == MAX_SIZE-1) {
            dequeue->front = 0;
        } else {
            dequeue->front++;
        }
        printf("Removed %d from the front of dequeue.\n", element);
        return element;
    }
}


int removeRear(Dequeue* dequeue) {
    if (isEmpty(dequeue)) {
        printf("Deque is empty.\n");
        return -1;
    } else {
        int element = dequeue->items[dequeue->rear];
        dequeue->rear = (dequeue->rear - 1 + MAX_SIZE) % MAX_SIZE;
        printf("Removed %d from rear of dequeue.\n", element);
        return element;
    }
}

int main()
{
Dequeue* dq = createDequeue();
addRear(dq,10);
addFront(dq,1);
removeFront(dq);
removeRear(dq);
return 1;	
}
