#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a = 3;
    int b = 4;
    int c = 6;
    printf("%d",a>b?(a>c?a:c):(b>c?b:c));
    return 0;
}