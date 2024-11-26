#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100 // Maximum size of the stack

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to evaluate a prefix expression
int evaluatePrefix(char *expression) {
    Stack stack;
    initStack(&stack);
    
    int length = strlen(expression);
    
    // Traverse the expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        // Skip spaces
        if (expression[i] == ' ') continue;

        // If the current character is an operand (number)
        if (isdigit(expression[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (i >= 0 && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i--;
            }
            i++; // Adjust index after the loop to avoid skipping a digit
            push(&stack, num);
        }
        // If the current character is an operator
        else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            switch (expression[i]) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': push(&stack, operand1 / operand2); break;
                case '^': push(&stack, pow(operand1, operand2)); break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }

    // The final result will be the only element left in the stack
    return pop(&stack);
}

int main() {
    char expression[MAX];

    printf("Enter a prefix expression (e.g., + 9 * 2 3):\n");
    fgets(expression, MAX, stdin);

    // Remove trailing newline if it exists
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluatePrefix(expression);
    printf("The result of the prefix expression is: %d\n", result);

    return 0;
}