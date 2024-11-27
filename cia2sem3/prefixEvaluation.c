#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Stack structure
typedef struct {
    int *data;    // Dynamic array for stack elements
    int top;      // Index of the top element
    int capacity; // Current capacity of the stack
} Stack;

// Function to initialize the stack
void initStack(Stack *stack, int initialCapacity) {
    stack->data = (int *)malloc(initialCapacity * sizeof(int));
    if (!stack->data) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = initialCapacity;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to resize the stack if it's full
void resizeStack(Stack *stack) {
    stack->capacity *= 2; // Double the capacity
    stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
    if (!stack->data) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        resizeStack(stack);
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
int evaluatePrefix(char *expression, Stack *stack) {
    int length = strlen(expression);

    // Iterate through the expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        // Skip spaces in the expression
        if (expression[i] == ' ') continue;
   
// * -  1 2 + 16  6+1    num  = 0       

        // Check if the current character is a digit
        if (isdigit(expression[i])) {
            // Initialize a variable to build the number
            int num = 0;
            // Continue to the left as long as the characters are digits
            while (i >= 0 && isdigit(expression[i])) {
                // This loop is handling the extraction of a multi-digit number from the expression.
                // It iterates through the expression from right to left, converting each digit character
                // to its integer value and adding it to the number. The loop stops when it encounters
                // a non-digit character or reaches the beginning of the expression.
                num = num * 10 + (expression[i] - '0');
                i--;
            }
            // After the loop, move back to the right to continue processing the expression
            i++; 
            // Push the number onto the stack
            push(stack, num);
        } else {
            int operand1 = pop(stack);
            int operand2 = pop(stack);

            switch (expression[i]) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
                case '^': push(stack, pow(operand1, operand2)); break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }

    return pop(stack);
}

int main() {
    int initialSize;
    printf("Enter the initial size of the stack: ");
    scanf("%d", &initialSize);

    if (initialSize <= 0) {
        printf("Invalid size. Exiting program.\n");
        return 1;
    }

    Stack stack;
    initStack(&stack, initialSize);

    char expression[] = "+ 9 * 2 3"; // Directly assign the prefix expression

    int result = evaluatePrefix(expression, &stack);
    printf("The result of the prefix expression is: %d\n", result);

    free(stack.data);
    return 0;
}
