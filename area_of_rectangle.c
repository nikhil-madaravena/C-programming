#include<stdio.h>
int main()
{
	int l,b;
	float p,a;
	printf("Enter the length & width of the rectangle: ");
	scanf("%d%d",&l,&b);
	p=2.0*(l+b);
	a=l*b; 
	
	printf("The Perimeter and area of rectangle = %f, %f units\n",p,a);
}