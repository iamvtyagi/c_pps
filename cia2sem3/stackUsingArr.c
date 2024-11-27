#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;      // Pointer to the stack array
    int top;       // Index of the top element
    int capacity;  // Current capacity of the stack
} Stack;

// Function to initialize the stack
void initStack(Stack *stack, int capacity) {
    stack->arr = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
}

// Function to resize the stack when needed
void resizeStack(Stack *stack) {
    stack->capacity *= 2;
    stack->arr = (int *)realloc(stack->arr, stack->capacity * sizeof(int));
    printf("Stack resized to capacity %d\n", stack->capacity);
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        resizeStack(stack); // Resize stack if full
    }
    stack->arr[++stack->top] = value;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
void pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack->arr[stack->top--]);
    }
}

// Function to peek the top element
int peek(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to display all elements in the stack
void display(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to free memory allocated for the stack
void freeStack(Stack *stack) {
    free(stack->arr);
}

int main() {
    Stack stack;
    int initialCapacity = 2; // Initial capacity of the stack
    initStack(&stack, initialCapacity);

    int n, value;

    // Ask the user how many elements they want to push
    printf("How many elements do you want to push into the stack? ");
    scanf("%d", &n);

    // Input values and push them into the stack
    printf("Enter the %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    // Display the stack
    printf("\nStack after pushing %d elements:\n", n);
    display(&stack);

    // Optional operations
    printf("\nPerforming pop operation:\n");
    pop(&stack);

    printf("Stack after pop operation:\n");
    display(&stack);

    printf("top of the stack is %d",peek(&stack));

    freeStack(&stack); // Free the memory
    return 0;
}
