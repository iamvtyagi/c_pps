#include<stdio.h>
 
 int fibb(int n){
    if(n==1){
        return 0;
    }
    else if(n ==2){
        return 1;
    }
  else{
    return fibb(n-1) + fibb(n-2);
  }
 }
int main(){
     int n;
     int sum = 0;
     printf("enter the value of n : ");
     scanf("%d", &n);
    for(int i = 1;i<=n;i++){
        int j;
        j = fibb(i);
        sum+=j;
        printf(" %d", j);
    }
    printf("\nsum of fib series is %d ", sum);
    return 0;
}