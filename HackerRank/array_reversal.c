#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr,temp;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(int i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    for(int i=0;i<num/2;i++){
        temp=*(arr+i);
        *(arr+i)=*(arr+num-1-i);
        *(arr+num-1-i)=temp;
    }

    for(int i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
