#include <stdio.h>

int countTokens(char str[]) {
    int count = 0;
    int isToken = 0; 

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] != ' ' && isToken == 0) {
            count++;
            isToken = 1; 
        }
        else if (str[i] == ' ') {
            isToken = 0;
        }
    }
    return count;
}

int main() {
    char A[1000];
    printf("Enter a string : ");
    scanf("%[^\n]%*c",&A);
    int tokens = countTokens(A);
    
    printf("Tokens: %d\n", tokens);
    
    return 0;
}
