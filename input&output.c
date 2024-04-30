#include<stdio.h>
int main()
{
	int i;
	char c;
	float f;
	
	printf("Enter a character: ");
	scanf("%c",&c);
	printf("Enter the integer: ");
	scanf("%d",&i);
	printf("Enter the float value: ");
	scanf("%f",&f);
	
	printf("Character: %C\n",c);
	printf("Integer value: %d\n",i);
	printf("Float value: %f\n",f);
	
}