#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Function to create a new node
struct DNode* createDNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the doubly linked list
void appendD(struct DNode** head, int data) {
    struct DNode* newNode = createDNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct DNode* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the doubly linked list
void displayD(struct DNode* head) {
    struct DNode* temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the doubly linked list
void deleteD(struct DNode** head, int data) {
    if (*head == NULL) return;

    struct DNode* temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        if (*head) (*head)->prev = NULL;
        free(temp);
        return;
    }

    // This loop traverses the doubly linked list until it finds the node with the specified data or reaches the end of the list.
    // The loop condition checks if the current node (temp) is not NULL and its data is not equal to the data we're searching for.
    // If the condition is true, it moves to the next node in the list.
    while (temp && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;

    free(temp);
}

// Main function for testing
int main() {
    struct DNode* head = NULL;
    appendD(&head, 10);
    appendD(&head, 20);
    appendD(&head, 30);
    displayD(head);

    deleteD(&head, 20);
    displayD(head);
    return 0;
}

