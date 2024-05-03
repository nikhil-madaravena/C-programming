/*
dynamic memory allocation
4 functions
1. Malloc -
    dynamically allocate memory block and return a pointer to it
    syntax - ptr=(data type *)malloc(size(int))

2. Calloc -
    dyanamically allocate blocks of memory and return a pointer to the first block and link the remaining blocks
    syntax - ptr=(data type *)calloc(n, sizeof(int))

3. Free -
    dynamically free memory block
    syntax - free(ptr)

4. Realloc -
    dyanamically reallocate the size of memory block
    syntax - ptr=realloc(new size).
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    //dynamically allocating memory
    ptr=(int *)malloc(sizeof(int));
    printf("Enter a value :");
    scanf("%d",ptr);
    printf("Enter value in dyamically allocated memory : %d",*ptr);
    free(ptr);//free the memory block

    //dma for 1D array
    int n;
    printf("Enter size :");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));

    printf("Enter array :");
    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }

    printf("Entered array is :");
    for(int i=0;i<n;i++){
        printf("%d",*(ptr+i));
    }
    free(ptr);

    //dma for 2D array
    int m;
    printf("Enter order of the matrix :");
    scanf("%d",&m);   //mxm matrix
    ptr = (int *)malloc(m*m*sizeof(int));
    printf("Enter matrix elements :");
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d",(ptr+i*m+j));
        }
    }
    printf("Array elements are :");
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            printf("%d",*(ptr+i*m+j));
        }
    }
}


