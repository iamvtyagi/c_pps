#include<stdio.h>
int fibo(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    return fibo(n-1)+fibo(n-2);
}
int main(){
     int n;
     printf("enter the value of n : ");
     scanf("%d",&n);
     int sum = 0;
     for(int i = 1;i<=n;i++){
        sum += fibo(i);
        printf("%d ",fibo(i));
     }
     printf(" sum of fibo series is %d",sum);
    return 0;
}