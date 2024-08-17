#include<stdio.h>

int fac(int n){
    if(n == 0){
        return 1;
    }
   return n*fac(n-1);
}

int main(){
    int n;
    printf("enter the value of n : ");
    scanf("%d",&n);
    int b = fac(n);
    printf("ans is %d",b);
    return 0;
}