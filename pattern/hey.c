#include <stdio.h>

int main() {
    // File pointers for reading and writing
    FILE *writePtr, *readPtr;
    
    // Open file for writing ("w" mode)
    writePtr = fopen("example.txt", "w");
    if (writePtr == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    
    // Write text to file
    fprintf(writePtr, "Hello, this is a sample text written to the file.\n");
    fprintf(writePtr, "Let's read this text from the file and display it.\n");

    // Close the file after writing
    fclose(writePtr);

    // Open file for reading ("r" mode)
    readPtr = fopen("example.txt", "r");
    if (readPtr == NULL) {
        perror("Error opening file for reading");
        return 1;
    }
    

     char ch;
    while(1){
        ch = fgetc(readPtr);
        if(ch == EOF){
            printf("khatam!!");
            exit(0);
        }
       else{
        printf("%c",ch);
       }
    }

    // Close the file after reading
    fclose(readPtr);

    return 0;
}
