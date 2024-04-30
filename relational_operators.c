#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter a value: ");
	scanf("%d",&a);
	printf("Enter b value: ");
	scanf("%d",&b);
	
	printf("A<=B: %d\n",a<=b);
	printf("A>B: %d\n",a>b);
	printf("A!=B: %d\n",a!=b);
}