#include<stdio.h>
#define SIZE 5
int rear=-1,front=-1;
int q[SIZE];

void enqueue(int data)
{
	if(rear == SIZE-1)
	{
		printf("queue is full\n");
		return;
	}
	if(front == -1)
	front=0;
	q[++rear]=data;
}

int dequeue()
{
	if(front == -1 || front > rear)
	{
		printf("queue is empty\n");
		return -1;
	}
	return q[front++];
}

int peek()
{
	if(front == -1 || front > rear)
	{
		printf("queue is empty\n");
		return -1;
	}
	return q[front];
}

void print()
{
	int i;
	if(front == -1 || front > rear)
	{
		printf("queue is empty\n");
		return;
	}
	for(i=front;i<=rear;i++)
	printf("%d\n",q[i]);
	
}

int main()
{
	dequeue();	
	enqueue(1);
	enqueue(2);
	print();
	printf("dequeued: %d\n",dequeue());
	printf("dequeued: %d\n",dequeue());
	printf("dequeued: %d\n",dequeue());
	return 1;
}
