#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    //dynamically allocating memory
    ptr=(int *)calloc(1,sizeof(int));
    printf("Enter a value :");
    scanf("%d",ptr);
    printf("the value in dyanamically allocated memory : %d\n",*ptr);
    free(ptr);//free the memory block

    //dma for 1D array
    int n;
    printf("Enter size :");
    scanf("%d",&n);
    ptr=(int *)calloc(n,sizeof(int));

    printf("Enter array :");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }

    printf("Entered array is :");
    for(int i=0;i<n;i++){
        printf("%d",*(ptr+i));
    }
    free(ptr);
}


