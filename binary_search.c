#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements (sorted order)\n");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    printf("Enter key element\n");
    int key,pos=-1;
    scanf("%d",&key);

    int mid,lb=0,ub=n-1;
    while(lb<=ub){
        mid = lb + (lb + ub)/2;
        if(a[mid]==key){
            pos=mid;
            break;
        }  
        else if(a[mid]<key){
            ub = mid - 1;
        }
        else{
            lb = mid + 1;
        }
    }

        if(pos!=-1)
        printf("Element found at position %d\n",pos);
        else
        printf("No element found in the array\n");
}