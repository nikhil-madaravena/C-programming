#include <stdio.h>

int min(int a, int b) {
    return (a <= b) ? a : b;
}

int fibonacciSearch(int arr[], int target, int n) {
    int fib2 = 0;   // (m-2) Fibonacci number
    int fib1 = 1;   // (m-1) Fibonacci number
    int fibM = fib2 + fib1; // m'th Fibonacci number

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < target) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        else if (arr[i] > target) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }
        else return i;
    }

    if (fib1 && arr[offset + 1] == target)
        return offset + 1;

    return -1;
}

int main() {

    int n,target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\n");
    printf("Enter the target element to search: ");
    scanf("%d", &target);
    printf("\n");
    int index = fibonacciSearch(arr, target, n);

    if (index >= 0) {
        printf("Found at index: %d\n", index);
    } else {
        printf("Not found\n");
    }

    return 0;
}
