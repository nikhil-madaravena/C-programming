#include<stdio.h>
int fibonacci(int n)
{
    if(n<=1)
    return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    printf("Enter the limit of fibonacci series(n): ");
    scanf("%d",&n);
    printf("Fibonacci series upto %d terms:  ",n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",fibonacci(i));
    }
}