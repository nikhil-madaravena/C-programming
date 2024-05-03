#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char ab[20], ba[20];
    sprintf(ab, "%d%d", *(const int*)a, *(const int*)b);
    sprintf(ba, "%d%d", *(const int*)b, *(const int*)a);
    return strcmp(ba, ab);
}

void print_largest_number(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}

int main() {
    int i,o;
    printf("enter size of array : ");
    scanf("%d",&o);
    int arr[o];
    printf("Enter array elements : ");
    for(i=0;i<o;i++)
    {
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    print_largest_number(arr, n);
    return 0;
}
