#include <stdio.h>
#include <stdlib.h>

// Function to find the least greater element on the right
int findLeastGreater(int arr[], int n, int element) {
    int minGreater = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > element && (minGreater == -1 || arr[i] < arr[minGreater])) {
            minGreater = i;
        }
    }

    return minGreater;
}

// Function to replace array elements with the least greater element on the right
void replaceWithLeastGreater(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int index = findLeastGreater(arr, n, arr[i]);

        if (index != -1) {
            arr[i] = arr[index];
        } else {
            arr[i] = -1;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    replaceWithLeastGreater(arr, n);

    printf("Array after replacement: ");
    printArray(arr, n);

    return 0;
}
