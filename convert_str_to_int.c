#include <stdio.h>

int converting(const char *str) {
    int result = 0;
    int sign = 1; 

    if (*str == '-') {
        sign = -1;
        str++;
    }
    
    while (*str != '\0') {
        
        if (*str >= '0' && *str <= '9') {
            
            result = result * 10 + (*str - '0');
        } else {
            
            break;
        }
        str++; 
    }
    
    return result * sign; 
}

int main() {
    char str[100];

    printf("Enter a string : ");
    gets(str);

    int convertedInt = converting(str);
    printf("Converted integer: %d\n", convertedInt);

    return 0;
}
