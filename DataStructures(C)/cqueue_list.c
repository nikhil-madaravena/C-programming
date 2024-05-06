#include <stdio.h>
#include <stdlib.h>


typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;


typedef struct {
    QueueNode *front, *rear;
    int size;
} CircularQueue;


void initQueue(CircularQueue *q) {
    q->front = q->rear = NULL;
    q->size = 0;
}


void enqueue(CircularQueue *q, int data) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    if (q->front == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->rear->next = q->front;
    q->size++;
    printf("%d enqueued to the queue\n", data);
    
}


void dequeue(CircularQueue *q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    int data = q->front->data;
    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        QueueNode *temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->rear->next = q->front;
    }
    q->size--;
    printf("%d dequeued from the queue\n", data);
}


int peek(CircularQueue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}


int isEmpty(CircularQueue *q) {
    if (q->front == NULL) {
        return 1;
    }
    return 0;
}


int isFull(CircularQueue *q) {
    return 0;
}


int size(CircularQueue *q) {
    return q->size;
}


CircularQueue clone(CircularQueue *src) {
	CircularQueue dst;
	initQueue(&dst);
    QueueNode *cur = src->front;
    
    do {
        enqueue(&dst, cur->data);
        cur = cur->next;
    }while(cur != src->front);
    return dst;
}


void clear(CircularQueue *q) {
    while (q->front != NULL) {
        dequeue(q);
    }
}


int search(CircularQueue *q, int data) {
    QueueNode *cur = q->front;
    int index = 0;
    while (cur != NULL) {
        if (cur->data == data) {
            return index;
        }
        cur = cur->next;
        index++;
    }
    return -1;
}

void printQueue(CircularQueue *q) {
	QueueNode *cur = q->front;
	if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Elements in the queue: ");
    
    do{
        printf("%d\n", cur->data);
        cur = cur->next;
    }while(cur != q->front);
}

int main() {
    CircularQueue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Size of queue: %d\n", size(&q));
    printf("Front element: %d\n", peek(&q));
    CircularQueue copy;
    copy=clone(&q);
    printf("Size of copied queue: %d\n", size(&copy));
    printQueue(&copy);
    return 0;
}
