#include<stdio.h>

int fact(int n){
    if(n == 0){
        return 1;
    }
    else return (n*fact(n-1));
}
int main(){
    int n ,ans;
    printf("enter the value of n :");
    scanf(" %d",&n);
    ans = fact(n);
    printf("factorial of %d is %d", n,ans);
    return 0;
}