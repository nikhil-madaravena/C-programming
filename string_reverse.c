#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    printf("Enter a string: ");
    scanf("%s",a);

    printf("string: %s\n",a);
    int n=strlen(a);

    for(int i=0; i<n-1-i; i++)
    {
        
        a[i]=a[i]+a[n-i-1];
        a[n-i-1]=a[i]-a[n-i-1];
        a[i]=a[i]-a[n-i-1];
    }

    printf("reverse: %s\n",a);
}