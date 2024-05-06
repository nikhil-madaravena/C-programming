#include<stdio.h>
int taverse(int n,int a[n]){
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    return a;
}

void display(int n,int a[n]){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    traverse(n,a);
    printf("Array elements are: ");
    display(n,a);
}