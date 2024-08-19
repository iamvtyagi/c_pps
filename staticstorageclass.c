void incrementCounter() {
    static int counter = 0; // Initialized only once
    counter++;
    printf("Counter: %d\n", counter);
}

int main() {
    incrementCounter(); // Output: Counter: 1
    incrementCounter(); // Output: Counter: 2
    incrementCounter(); // Output: Counter: 3
    return 0;
}
