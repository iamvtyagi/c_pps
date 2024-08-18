#include<stdio.h>
#define a 3
#define b 2

int main(){
    #if (a>b)
        printf("hello");
    #elif (a==b)
        printf("vansh");
    #else 
        printf("tushar tyagi");
    #endif
    return 0;
}