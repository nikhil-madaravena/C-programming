#include<stdio.h>
int main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int num[10];

    for(int i = 0; i < 10; i++)
    {
        num[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(a[i] == j)
                num[j]++;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        if(num[i] != 0)
        printf("%d occurs %d times\n", i, num[i]);
    }
}