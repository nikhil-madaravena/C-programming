#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
struct node *front='\0', *rear='\0';

void enqueue(int data)
{
	struct node *newnode;
	newnode = (struct  node *)malloc(sizeof(struct node));
	newnode->data = data;
	if(front == '\0')
	{
		newnode->link = newnode;
		front=rear = newnode;
		return;
	}
	newnode->link = front;
	rear->link = newnode;
	rear = newnode;
	
}

int dequeue()
{
	struct node *temp;
	int n=0;
	if(front == '\0')
	{
		printf("list is empty\n");
		return;
	}
	temp = front;
	if(front  == rear)
		front = rear = '\0';
	else
	{
		front = front->link;
		rear->link = front;
	}
	n=temp->data;
	free(temp);
	return n;
	
}

int peep()
{
	if(front != '\0')
	return front->data;
	return -1;
}
void printqueue()
{
	struct node *temp;
	if(front == '\0')
	{
		printf("queue is empty\n");
		return;
	}
	temp = front;
	do
	{
		printf("%d\n",temp->data);
		temp = temp->link;
	}while(temp != front);
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	printqueue();
	printf("%d\n\n",peep());
	printf("%d\n\n",dequeue());
	printf("%d\n\n",peep());
	printqueue();
	return 1;
}

