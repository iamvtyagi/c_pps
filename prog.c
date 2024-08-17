#include<stdio.h>
#include<math.h>
int sumOfDigit(int n){
        int digit = 0;
    int sum = 0;
         while(n){
        digit = n % 10;
        sum += digit;
        n = n/10;  
         }   
}
void primeOrNot(int n){
    if(n<0){
        printf("number is -ve");
        return;
    }
    int isPrime = 1;
    int l = n/2;
 if(n == 0 || n==1){
        printf("not a prime number !!");
    }
    else{
        for(int i = 2;i<=l;i++){
            if(n%i ==0){
                printf("not a prime number ");
                isPrime = 0;
                break;
            }
        }
    }
    if(isPrime == 1){
        printf("number is prime");
    }
}
long int factorial(int n ){
    long int fact = 1;
    for(int i = 1;i<=n;i++){
        fact *= i;
    }
    return fact;
}
void sumUptoN(int n){
    printf("sum of numbers upto %d : %d\n",n, (n*(n+1))/2);
}
void revNum(int n){
    int rev = 0;
    int rem = 0;
    while(n){
       int digit = n%10;
        rev = (rev*10)+digit;
       n = n/10;
    }
    printf("reversed number is %d", rev);
}

 int main(){
    int n;
    printf("enter the value of n : ");
    scanf("%d", &n);
    
    // printf("sum of odd numbers is : %d", n*n);
//    primeOrNot(n);
//    sumUptoN(n);
    //  revNum(n);
    // int arr[3] = {1,2,4};
    // int max = arr[0];
    // int min = arr[0];
    // for(int i = 0;i<3;i++){
    //     if(arr[i]>max){
    //         max = arr[i];
    //     }
    //     if(arr[i]<min){
    //         min = arr[i];
    //     }
    // }
    // printf("maximum is %d and minimum is %d", max,min);

    
    int matrix[3][3]= {{1,2,3},{1,2,3},{1,2,3}};
       int main_sum = 0;
       int second_sum = 0;
       for(int i =0,j = 0;i<3,j<n;i++,j++){
        if(i == j){
            main_sum += matrix[i][j];
        }
       }
       for(int i = 0, j=2 ; i<3 && j>=0;i++,j--){
        second_sum += matrix[i][j];
       }
       printf("main_sum is %d and second sum is %d", main_sum,second_sum);
        
      return 0;
 }
 // file handaling