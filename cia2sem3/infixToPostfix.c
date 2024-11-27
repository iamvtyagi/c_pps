#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Structure to define a stack
typedef struct {
    char data[MAX];
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
void push(Stack *stack, char value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to peek at the top element of the stack
char peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return -1; // return -1 if stack is empty
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check operator precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char *expression, char *postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0; // Index for postfix expression

    for (int i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];

        // Skip spaces
        if (token == ' ') continue;

        // If the token is an operand (number/letter), add it to the postfix expression
        if (isalnum(token)) {
            postfix[j++] = token;
        }
        // If the token is '(', push it onto the stack
        else if (token == '(') {
            push(&stack, token);
        }
        // If the token is ')', pop from the stack until '(' is found
        else if (token == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop '(' from the stack
        }
        // If the token is an operator
        else if (isOperator(token)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (e.g., A + B * (C - D)):\n");
    fgets(infix, MAX, stdin);

    // Remove newline character from input
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}
