#include<stdio.h>
int main()
{
	float p,t,r,res=0;
	printf("Enter principal,rate and time: ");
	scanf("%f%f%f",&p,&t,&r);
	res=(p*t*r)/100;
	printf("Simple Interest = %f\n",res);
}