#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
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

// Function to peek the top element of the stack
char peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return -1;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check the precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to reverse the string
void reverse(char *expr) {
    int start = 0, end = strlen(expr) - 1;
    while (start < end) {
        char temp = expr[start];
        expr[start] = expr[end];
        expr[end] = temp;
        start++;
        end--;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (token == ' ') continue; // Skip spaces
        
        // If token is an operand, add to the postfix expression
        if (isalnum(token)) {
            postfix[j++] = token;
        }
        // If token is '(', push it onto the stack
        else if (token == '(') {
            push(&stack, token);
        }
        // If token is ')', pop until '(' is found
        else if (token == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from the stack
        }
        // If token is an operator
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

// Function to convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Convert the reversed infix expression to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Step 3: Reverse the postfix expression to get the prefix
    reverse(postfix);

    // Store the result in the prefix string
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression (e.g., (A + B) * (C - D)):\n");
    fgets(infix, MAX, stdin);

    // Remove the newline character at the end of the input
    infix[strcspn(infix, "\n")] = '\0';

    infixToPrefix(infix, prefix);

    printf("The prefix expression is: %s\n", prefix);

    return 0;
}
