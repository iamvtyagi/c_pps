#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void p1(int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i+1;j++){
            printf("%s ","*");
        }
        printf("\n");
    }
}
void p2(int m){
    int n = m-1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i;j++){
            printf("%s ","*");
        }
        printf("\n");
    }
}
int main(){

    int n,m;
    printf("enter the value of n : ");
    scanf("%d",&n);
    p1(n);
    p2(n);

    return 0;
}