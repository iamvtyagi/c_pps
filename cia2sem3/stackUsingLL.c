#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Stack structure
typedef struct {
    Node *top; // Pointer to the top of the stack
} Stack;

// Function to initialize the stack
void initStack(Stack *stack) {
    stack->top = NULL;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed. Stack Overflow.\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
void pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    Node *temp = stack->top;
    printf("%d popped from stack\n", temp->data);
    stack->top = stack->top->next;
    free(temp);
}

// Function to peek the top element
int peek(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// Function to display all elements in the stack
void display(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    Node *temp = stack->top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free all nodes in the stack
void freeStack(Stack *stack) {
    Node *current = stack->top;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
}

int main() {
    Stack stack;
    initStack(&stack);

    int n, value;

    // Ask the user how many elements they want to push
    printf("How many elements do you want to push into the stack? ");
    scanf("%d", &n);

    // Input values and push them onto the stack
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

    freeStack(&stack); // Free the memory
    return 0;
}
