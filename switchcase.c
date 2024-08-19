#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a;
    printf("enter the value for expression : ");
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("hello1\n");
        printf("hello1");
        break;
        case 2:
        printf("hello1\n");
        printf("hello2");
        break;
        default : 
        printf("hello default\n");
        printf("hello1");
    }
    return 0;
}