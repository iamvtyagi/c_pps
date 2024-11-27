#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node at a specific position
void deleteAtPosition(Node **head, int position) {
    if (*head == NULL) {
        printf("The list is empty. Deletion is not possible.\n");
        return;
    }

    Node *temp = *head;

    // If the head node is to be deleted
    if (position == 0) {
        *head = temp->next;
        printf("Deleted node at position %d with value %d\n", position, temp->data);
        free(temp);
        return;
    }

    // Find the node before the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is out of range
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of range. Deletion not possible.\n", position);
        return;
    }

    // Node to be deleted
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted node at position %d with value %d\n", position, nodeToDelete->data);

    free(nodeToDelete);
}

// Function to display the linked list
void displayList(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node *temp = head;
    printf("Linked List: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node *head = NULL;
    int n, value, position;

    // Insert elements into the linked list
    printf("How many elements do you want to insert? ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    // Display the list
    printf("Initial ");
    displayList(head);

    // Delete node at a specific position
    printf("Enter the position to delete: ");
    scanf("%d", &position);
    deleteAtPosition(&head, position);

    // Display the list after deletion
    printf("After deletion ");
    displayList(head);

    return 0;
}

        