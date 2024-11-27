#include <stdio.h>
#include <stdlib.h>

// Node structure for single-variable polynomial
struct Node {
    int coeff;  // Coefficient
    int exp;    // Exponent
    struct Node* next;
};
 

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in descending order of exponent
void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    
    struct Node* current = *poly;
    while (current->next != NULL && current->next->exp > exp) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to display a polynomial
void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) insertTerm(&result, sum, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    for (struct Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (struct Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            insertTerm(&result, coeff, exp);
        }
    }

    return result;
}

// Main function to test the implementation
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Polynomial 1: 5x^3 + 4x^2 + 2
    insertTerm(&poly1, 5, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 2, 0);

    // Polynomial 2: 3x^2 + x + 1
    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 1, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Addition
    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(sum);

    // Multiplication
    struct Node* product = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    displayPolynomial(product);

    return 0;
}
