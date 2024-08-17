#include <stdio.h>
#include <math.h>

int binaryToDecimal(long long n) {
    int decimalNumber = 0, i = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}
long long decimalToBinary(int n) {
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n != 0) {
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}
int main() {
    int choice;
    long long binaryInput=0;
    int decimalInput=0;
    printf(" choice 10 means you want to convert binary to deciaml 2 means you want to convert decimal to \n");
    printf("now enter your choice :");
    scanf("%d", &choice);
   switch(choice){
            case 10:
                printf("Enter a binary number: ");
                scanf("%lld", &binaryInput);
                printf("Decimal number is : %d\n", binaryToDecimal(binaryInput));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalInput);
                printf("Binary number is : %lld\n", decimalToBinary(decimalInput));
                break;
            default :
            printf("invalid input");
   }
   return 0;
}