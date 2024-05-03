#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of array\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    //traverse the array
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    //reverse the array
    for(int i=n-1; i>=0; i--)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    

    //insert any
    int key,pos;
    printf("Enter the ELEMENT and the POSITION you wish to insert\n");
    scanf("%d %d",&key,&pos);
    int temp = n;
    n++;
    for(int i=temp; i>=pos; i--)
    {
        if(i==pos)
        continue;
        a[i]=a[i-1];
    }
    a[pos]=key;
    for(int i=0; i<n; i++)
    printf("%d ", a[i]);

    //delete any
    printf("\nEnter the pos you want to detele\n");
    scanf("%d",&pos);
    for(int i=pos;i<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }

    //delete by element
    int el;
    pos=-1;
    printf("\nEnter the element you want to detele\n");
    scanf("%d",&el);
    for(int i=0;i<n;i++){
        if(el==a[i])
        pos=i;
    }
    if(pos=-1)
        printf("Element not found\n");
    else{
        for(int i=pos;i<n-1;i++){
                a[i]=a[i+1];
        }   
        n--;
        for(int i=0;i<n;i++){
            printf("%d ", a[i]);
        }
    }

    //sort array
    printf("unsorted array\n");
    for(int i=0;i<n;i++)
    printf("%d ", a[i]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]<a[i]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("Sorted array\n");
    for(int i=0;i<n;i++)
    printf("%d ", a[i]);

}