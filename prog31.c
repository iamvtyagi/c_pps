#include <stdio.h>
#include <stdlib.h>
int compareFiles(const char *file1, const char *file2) {
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: Could not open one or both files.\n");
        if (fp1 != NULL) fclose(fp1);
        if (fp2 != NULL) fclose(fp2);
        return -1;
    }
    char ch1, ch2;
    int areSame = 1;

    while (((ch1 = fgetc(fp1)) != EOF) && ((ch2 = fgetc(fp2)) != EOF)) {
        if (ch1 != ch2) {
            areSame = 0;
            break;
        }
    }
    // Check if both files have reached EOF
    if ((fgetc(fp1) != EOF) || (fgetc(fp2) != EOF))   areSame = 0;
    fclose(fp1);
    fclose(fp2);
    return areSame;
}
int main() {
    char file1[100], file2[100];

    printf("Enter the first filename: ");
    scanf("%s", file1);
    printf("Enter the second filename: ");
    scanf("%s", file2);
    int result = compareFiles(file1, file2);
    if (result == -1) {
        printf("An error occurred while opening the files.\n");
    } else if (result == 1) printf("The files are the same.\n");
    else  printf("The files are different.\n");
    return 0;
}
