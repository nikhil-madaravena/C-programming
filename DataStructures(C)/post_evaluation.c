#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
 

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
 

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack
        = (struct Stack*)malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array
        = (int*)malloc(stack->capacity * sizeof(int));
 
    if (!stack->array)
        return NULL;
 
    return stack;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
 
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
 
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}
 
int evaluatePostfix(char* exp)
{

    struct Stack* stack = createStack(strlen(exp));
    int i;
 

    if (!stack)
        return -1;
 

    for (i = 0; exp[i]; ++i) {
         
        if (isalpha(exp[i]))
        {
			int n;
			printf("Enter value for %c",exp[i]);
			scanf("%d",&n);
            push(stack, n);
        }
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            case '^':
            	push(stack,pow(val2,val1));
            	break;
            }
        }
    }
    return pop(stack);
}
 

int main()
{
    char exp[] = "abc^+";
   

    printf("postfix evaluation: %d", evaluatePostfix(exp));
    return 0;
}


