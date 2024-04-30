#include<stdio.h>
int main()
{
	int a,b;
	float e,f;
	char c;
	printf("Enter two integers: ");
	scanf("%d%d",&a,&b);
	printf("Enter two float values: ");
	scanf("%f%f",&e,&f);
	fflush(stdin);
	printf("Enter a character: ");
	scanf("%c",&c);
	printf("Integer with left justified: %-d\n",a);
	printf("Integer with right justified: %3d\n",b);
	printf("Float value with precision: %f\n",e);
	printf("Float value with precision: %.2f\n",f);
	printf("ASCII value of character: %d\n",c);
}