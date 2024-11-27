#include <stdio.h>

int main() {
    int i = 0;
    
    if (i == 0) {
        goto skip;
    }
    printf("This line is skipped.\n");

skip:
    printf("This line is executed.\n");
vansh:
    printf("hehehehehheheheheh");
    return 0;
}
