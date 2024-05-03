#include <stdio.h>
#include <stdlib.h>

void findKClosest(int arr[], int n, int target, int k);

int main() {
    int i, p;
    printf("Enter array size: ");
    scanf("%d", &p);

    int arr[p];

    for (i = 0; i < p; i++) {
        printf("Enter element %d : ",i+1);
        scanf("%d", &arr[i]);
    }

    int k, target;
    printf("Enter k value: ");
    scanf("%d", &k);
    printf("Enter target value: ");
    scanf("%d", &target);

    findKClosest(arr, p, target, k);

    return 0;
}

void findKClosest(int arr[], int n, int target, int k) {
    int left = 0, right = n - 1;
    int closestIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            closestIndex = mid;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (closestIndex == -1) {
        closestIndex = (left < n && (left == 0 || abs(arr[left] - target) < abs(arr[left - 1] - target))) ? left : left - 1;
    }
    int closestElement[k];
    int leftPointer = closestIndex, rightPointer = closestIndex + 1;

    for (int i = 0; i < k; i++) {
        if (leftPointer >= 0 && rightPointer < n) {
            if (abs(arr[leftPointer] - target) <= abs(arr[rightPointer] - target)) {
                closestElement[i]=arr[leftPointer];
                leftPointer--;
            } else {
                closestElement[i]=arr[rightPointer];
                rightPointer++;
            }
        } else if (leftPointer >= 0) {
            closestElement[i]=arr[leftPointer];
            leftPointer--;
        } else {
            closestElement[i]=arr[rightPointer];
            rightPointer++;
        }
    }

    int temp;;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(closestElement[i]>closestElement[j]){
                temp=closestElement[i];
                closestElement[i]=closestElement[j];
                closestElement[j]=temp;
            }
        }
    }
    for(int i=k-1;i>=0;i--){
        printf("%d ",closestElement[i]);
    }
}