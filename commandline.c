#include <stdio.h>

int main(int argc, char *argv[]) {
    // Print the number of command-line arguments
    printf("Number of arguments: %d\n", argc);

    // Print each command-line argument
    printf("Arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
