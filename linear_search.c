#include<stdio.h>
int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);

    int key,pos=-1,a[n];

    printf("Enter array elements : \n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

    printf("Enter key : ");
    scanf("%d",&key);

    //linear search
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        pos=i;
    }

    if(pos!=-1)
    printf("element found at pos : %d\n",pos);
    else
    printf("element not found\n");
}