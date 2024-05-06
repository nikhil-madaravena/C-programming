#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Structure for Stack using doubly linked list
struct Stack {
    struct Node* top;
};

// Function to initialize a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(stack)) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top->prev = newNode;
        stack->top = newNode;
    }
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* poppedNode = stack->top;
    int poppedValue = poppedNode->data;
    stack->top = poppedNode->next;

    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }

    free(poppedNode);
    return poppedValue;
}

// Function to display elements in the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){

    struct Stack *stack=createStack();
    int choice,data,index;
    while(choice!=4){
        printf("\n 1. Push \n 2. Pop \n 3. display \n 4. exit \n ");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to push into the stack : ");
            scanf("%d",&data);
            push(stack,data);
            break;
        case 2:
            printf("Popped : %d\n",pop(stack));
            break;
        case 3:
            displayStack(stack);
            break;
        default:
        printf("Enter valid input !!!!");
            break;
        }
    }
}
