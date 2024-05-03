#include <stdio.h>

void count(int n1, int n2) {
    int no_of_digits[10] = {0}; 
    
    for (int i = n1; i <= n2; i++) {
        int num = i;
        while (num > 0) {
            int digit = num % 10;
                no_of_digits[digit]++; 
            num /= 10; 
        }
    }

    printf("Number of 0s-- %d\t", no_of_digits[0]);
    printf("Number of 1s-- %d\n", no_of_digits[1]);
    printf("Number of 2s-- %d\t", no_of_digits[2]);
    printf("Number of 3s-- %d\n", no_of_digits[3]);
    printf("Number of 4s-- %d\t", no_of_digits[4]);
    printf("Number of 5s-- %d\n", no_of_digits[5]);
    printf("Number of 6s-- %d\t", no_of_digits[6]);
    printf("Number of 7s-- %d\n", no_of_digits[7]);
    printf("Number of 8s-- %d\t", no_of_digits[8]);
    printf("Number of 9s-- %d\n", no_of_digits[9]);
}

int main() {
    int n1, n2;

    printf("Enter two numbers (n1 and n2): ");
    scanf("%d %d", &n1, &n2);

    count(n1, n2);

    return 0;
}
