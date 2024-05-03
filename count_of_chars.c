#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int frequency[256] = {0};  // Array to hold frequencies of ASCII characters
    int i;

    // Read string input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate frequency of each character
    for(i = 0; str[i] != '\0'; i++) {
        frequency[(int)str[i]]++;
    }

    // Display the frequencies
    printf("Character frequencies:\n");
    for(i = 0; i < 256; i++) {
        if(frequency[i] != 0) {
            printf("'%c' = %d\n", i, frequency[i]);
        }
    }

    return 0;
}