#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;  // Dynamically allocated array for queue
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int capacity; // Capacity of the queue
} Queue;

// Function to initialize the queue
void initQueue(Queue *queue, int capacity) {
    queue->arr = (int *)malloc(capacity * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

// Function to resize the queue when full
void resizeQueue(Queue *queue) {
    queue->capacity *= 2;
    queue->arr = (int *)realloc(queue->arr, queue->capacity * sizeof(int));
    printf("Queue resized to capacity %d\n", queue->capacity);
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        resizeQueue(queue); // Resize queue if full
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Set front to 0 for the first element
    }
    queue->arr[++queue->rear] = value;
    printf("%d added to the queue\n", value);
}

// Function to remove an element from the queue (dequeue)
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d removed from the queue\n", queue->arr[queue->front]);
    queue->front++;
    if (queue->front > queue->rear) { // Reset queue when empty
        queue->front = queue->rear = -1;
    }
}

// Function to display the queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Function to free memory allocated for the queue
void freeQueue(Queue *queue) {
    free(queue->arr);
}

int main() {
    Queue queue;
    int initialCapacity = 2; // Initial capacity of the queue
    initQueue(&queue, initialCapacity);

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
