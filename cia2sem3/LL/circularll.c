#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning
void insertAtBeginning(struct Node** tail, int data) {
    struct Node* newNode = createNode(data);

    if (*tail == NULL) {
        // If the list is empty, point the new node to itself
        newNode->next = newNode;
        *tail = newNode;
    } else {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
    }
}

// Function to insert at the end
void insertAtEnd(struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
   

    if (*tail == NULL) {
        // If the list is empty, point the new node to itself
        newNode->next = newNode;
        *tail = newNode;
    } else {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Function to delete a node with a specific value
void deleteNode(struct Node** tail, int key) {
    if (*tail == NULL) {
        printf("List is empty, cannot delete\n");
        return;
    }  

    struct Node* current = (*tail)->next;
    struct Node* prev = *tail;

    // If the list contains only one node
    if (current == *tail && current->data == key) {
        free(current);
        *tail = NULL;
        return;
    }

    // Traverse and find the node to delete
    do {
        if (current->data == key) {
            prev->next = current->next;
            if (current == *tail) {
                *tail = prev; // Update tail if the node to delete is the tail
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != (*tail)->next);

    printf("Node with value %d not found\n", key);
}

// Function to display the list
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = tail->next;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("(HEAD)\n");
}

// Function to search for an element
void search(struct Node* tail, int key) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = tail->next;
    do {
        if (current->data == key) {
            printf("Element %d found in the list\n", key);
            return;
        }
        current = current->next;
    } while (current != tail->next);

    printf("Element %d not found in the list\n", key);
}

// Main function for testing
int main() {
    struct Node* tail = NULL; // Initially, the list is empty

    // Insert elements
    insertAtEnd(&tail, 10);
    insertAtEnd(&tail, 20);
    insertAtBeginning(&tail, 5);
    insertAtEnd(&tail, 30);

    // Display the list
    printf("Circular Linked List: ");
    display(tail);

    // Search for an element
    search(tail, 20);
    search(tail, 40);

    // Delete a node
    deleteNode(&tail, 20);
    printf("After deleting 20: ");
    display(tail);

    deleteNode(&tail, 5);
    printf("After deleting 5: ");
    display(tail);

    return 0;
}
