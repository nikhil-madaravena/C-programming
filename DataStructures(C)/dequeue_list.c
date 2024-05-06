#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *front='\0',*rear='\0';

void enqueue_front(int data)
{
	struct node *newnode ='\0';
	newnode =(struct node *)malloc(sizeof(struct node));
	newnode->data =data;
	newnode->link=front;
	if(front == '\0')
	front = rear = newnode;
	else
	front = newnode;
}

void enqueue_rear(int data)
{
	struct node *newnode ='\0';
	newnode =(struct node *)malloc(sizeof(struct node));
	newnode->data =data;
	newnode->link  = '\0';
	if(front == '\0')
	{
		front = rear = newnode;
		return;
	}
	rear->link = newnode;
	rear = newnode;
}
int dequeue_front()
{
	struct node *temp;
	int n=0;
	if(front == '\0')
	{
		printf("Queue is empty\n");
		return -1;
	}
	temp = front;
	n = temp->data;
	front = front->link;
	if(front == '\0')
	rear = '\0';
	free(temp);
	return n;
}

int dequeue_rear()
{
	struct node *temp,*curr;
	int n=0;
	if(front ==  '\0')
	{
		printf("Queue is empty\n");
		return;
	}
	curr = front;
	while(curr->link != rear)
	curr=curr->link;
	temp =  rear;
	n=temp->data;
	curr->link = '\0';
	rear =  curr;
	free(temp);
	return n;
}

void print()
{
	struct node *temp;
	if(front == '\0')
	{
		printf("Queue is empty\n");
		return;
	}
	temp = front;
	while(temp!='\0')
	{
		printf("%d\n",temp->data);
		temp = temp->link;
	}	
}

int main()
{
	enqueue_front(10);
	enqueue_rear(20);
	print();
	dequeue_rear();
	dequeue_front();
	print();
	return 1;	
}



