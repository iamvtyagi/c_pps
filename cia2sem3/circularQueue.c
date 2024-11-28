#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the maximum size of the circular queue

typedef struct {
    int data[SIZE];
    int front, rear;
} CircularQueue;

// Initialize the circular queue
void initQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int isEmpty(CircularQueue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % SIZE == queue->front;
}

// Enqueue an element into the queue
void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot add %d.\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0; // First element
    } else {
        queue->rear = (queue->rear + 1) % SIZE;
    }
    queue->data[queue->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Dequeue an element from the queue
void dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    int removedValue = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Queue becomes empty
    } else {
        queue->front = (queue->front + 1) % SIZE; 
    }
    printf("%d dequeued from the queue.\n", removedValue);
}

// Peek the front element
int peek(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return queue->data[queue->front];
}

// Display the queue elements
void display(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->data[i]);
        if (i == queue->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to test the circular queue
int main() {
    CircularQueue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    display(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display(&queue);

    enqueue(&queue, 60);
    enqueue(&queue, 70);

    display(&queue);

    printf("Front element is: %d\n", peek(&queue));

    return 0;
}
