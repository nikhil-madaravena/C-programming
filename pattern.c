#include <stdio.h>
int main()
{
    int n;
    printf("Enter n value : ");
    scanf("%d", &n);
    int i,j,k,h;
    for (i = 1; i <= n; ++i)
    {
        for( j = i-1; j <= n; j++)
        {
            printf("\t");
        }
        for( k=1; k <= i; k++)
        {
            printf("%d\t",k);
        }
        for( h = i-1; h > 0; h--)
        {
        printf("%d\t",h);
        }
        printf("\n");
    }
    for ( i = n; i > 0 ; i--)
    {
        for( j = i-1; j <= n; j++)
        {
            printf("\t");
        }
        for( k=1; k <= i-1; k++)
        {
            printf("%d\t",k);
        }
        for( h = i-2; h > 0; h--)
        {
        printf("%d\t",h);
        }
        printf("\n");
    }
}
