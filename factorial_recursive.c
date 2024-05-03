#include<stdio.h>
int factorial(int);
int main()
{
    int n;
    printf("Enter a number :");
    scanf("%d",&n);
    int fact=factorial(n);
    printf("Factorial of the given number is: %d\n",fact);
}

int factorial(int n)
{
    if(n==0)
    return 1;
    else
    return n*factorial(n-1);
}