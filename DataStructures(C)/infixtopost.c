#include<stdio.h>

int priority(char ch)
{
	if(ch=='^')
	return 3;
	else if(ch== '*' || ch=='/')
	return 2;
	else if(ch=='+' || ch=='-')
	return 1;
	return -1;
}
int isAlpha(char ch)
{
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	return 1;
	return 0;
}

void infixtopost(char exp[])
{
	char stack[100];
	char post[100];
	int i,j=0;
	int top=-1;
	char ch=' ';
	for(i=0;exp[i] != '\0';i++)
	{
		ch =exp[i];
		if(isAlpha(ch))
		{
			post[j++]=ch;
		}
		else if(ch == '(')
			stack[++top]='(';
		else if(ch == ')')
		{
			while(stack[top]!='(')
			post[j++]=stack[top--];
			top--;
		}
		else
		{
			while(top != -1 && priority(ch)<=priority(stack[top]))
			post[j++]=stack[top--];
			stack[++top]=ch;
		}
		
	}
	while(top != -1)
	{
		post[j++]= stack[top--];
	}
	post[j]='\0';
	printf("post fix : %s",post);
}

int main()
{
	char infix[80] ="a+(b-c)*d";
	infixtopost(infix);	
	return 1;
}
