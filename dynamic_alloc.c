#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,*p;
    printf("Enter array size: "); 
    scanf("%d",&n);

    p = (int *)malloc(n*sizeof(int));
    printf("Enter array elements: "); 
    for(int i=0;i<n;i++){
    scanf("%d",(p+i));
    }

    for(int i=0;i<n;i++){
        printf("%d",*(p+i));
    }
}