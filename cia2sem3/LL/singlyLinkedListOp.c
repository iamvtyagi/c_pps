#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

// Function to insert node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete node at beginning
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    } 
    
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete node at end
void deleteAtEnd(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        deleteAtBeginning(head);
        return;
    }
       

    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete node at position
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position\n");
        return;
    }
    
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    

    Node* temp = *head;
    for (int i = 0; i < position - 2 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Function to print linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes at beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);

    // Print linked list
    printf("Linked List after inserting at beginning:\n");
    printList(head);

    // Insert node at end
    insertAtEnd(&head, 30);

    // Print linked list again
    printf("Linked List after inserting at end:\n");
    printList(head);

    // Delete node at beginning
    deleteAtBeginning(&head);

    // Print linked list after deletion
    printf("Linked List after deleting at beginning:\n");
    printList(head);

    // Delete node at end
    deleteAtEnd(&head);

    // Print final linked list
    printf("Final Linked List after deleting at end:\n");
    printList(head);

    // Attempt to delete non-existent node
    deleteAtPosition(&head, 5);

    return 0;
}