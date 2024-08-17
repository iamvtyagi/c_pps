#include<stdio.h>
int revNum(int *n){
    int rem = 0;
    int rev = 0;
    
    while(*n){
        rem = *n%10;
        rev = rev*10 + rem;
        *n = *n/10;
    }
    return rev;
}
int main(){
    int n;
    printf("enter the value of n :");
    scanf("%d",&n);
    int b = n;
     n = revNum(&n);
     printf("reversed of %d is %d", b,n);
    return 0;
}