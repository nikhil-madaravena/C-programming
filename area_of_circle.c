#include<stdio.h>
int main()
{
	float r,a,p;
	float pi=3.14;
	printf("Enter radius of circle: ");
	scanf("%f",&r);
	a=pi*r*r;
	p=2.0*pi*r;
	printf("Area of circle: %f\n",a);
	printf("Perimeter of circle: %f\n",p);
	
}