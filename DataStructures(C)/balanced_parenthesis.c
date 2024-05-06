#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100


bool isOpeningParenthesis(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}


bool isClosingParenthesis(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}


bool isValidPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));
}


bool isBalanced(char expression[]) {
    char stack[MAX_SIZE];
    int top = -1; 
	int i;
    
    for (i = 0; expression[i] != '\0'; i++) {
    
        if (isOpeningParenthesis(expression[i])) {
            stack[++top] = expression[i];
        }
    
        else if (isClosingParenthesis(expression[i])) {
    
            if (top == -1 || !isValidPair(stack[top], expression[i])) {
                return false;
            }
            top--;
        }
    }


    return top == -1;
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("Balanced parentheses.\n");
    } else {
        printf("Unbalanced parentheses.\n");
    }

    return 0;
}

