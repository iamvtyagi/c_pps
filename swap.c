#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=  *b;
    *b = temp;
    printf("value of a and b after swapping is %d and %d\n", *a,*b);
}

int main(){
    int a;
    int b;
    printf("enter the value of a and b : ");
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("value of a and b after swapping is %d and %d\n",a,b);
    return 0;
}