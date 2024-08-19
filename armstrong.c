#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to count the number of digits in a number
int digits(int n) {
    int count = 0;
    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int n, int l) {
    int sum = 0;
    int m = n;

    while (n > 0) {
        int digit = n % 10;
        sum += (int)pow(digit, l);  // Use (int) to cast the result of pow to int
        n = n / 10;
    }
    
    return (sum == m);  // Return 1 if it is an Armstrong number, 0 otherwise
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int l = digits(n);
    int ans = isArmstrong(n, l);

    if (ans) {
        printf("%d is an Armstrong number.\n", n);
    } else {
        printf("%d is not an Armstrong number.\n", n);
    }

    return 0;
}
