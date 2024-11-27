#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Queue structure
typedef struct {
    Node *front; // Pointer to the front node
    Node *rear;  // Pointer to the rear node
} Queue;

// Function to initialize the queue
void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed. Unable to enqueue %d.\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode; // For the first element
    } else {
        queue->rear->next = newNode; // Add new node at the end
        queue->rear = newNode;
    }
    printf("%d added to the queue\n", value);
}

// Function to dequeue an element from the queue
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow. No elements to dequeue.\n");
        return;
    }
    Node *temp = queue->front;
    printf("%d removed from the queue\n", temp->data);
    queue->front = queue->front->next;

    if (queue->front == NULL) { // Queue becomes empty
        queue->rear = NULL;
    }
    free(temp);
}

// Function to display the queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    Node *temp = queue->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for the queue
void freeQueue(Queue *queue) {
    Node *current = queue->front;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    queue->front = queue->rear = NULL;
}

int main() {
    Queue queue;
    initQueue(&queue);

    int n, value;

    // Ask the user how many elements they want to enqueue
    printf("How many elements do you want to enqueue into the queue? ");
    scanf("%d", &n);

    // Input values and enqueue them into the queue
    printf("Enter the %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    // Display the queue
    printf("\nQueue after enqueuing %d elements:\n", n);
    display(&queue);

    // Optional operations
    printf("\nPerforming dequeue operation:\n");
    dequeue(&queue);

    printf("Queue after dequeue operation:\n");
    display(&queue);

    freeQueue(&queue); // Free the memory
    return 0;
}
