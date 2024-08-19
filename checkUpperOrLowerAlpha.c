#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char ch;
    printf("enter the char : ");
    scanf("%c",&ch);
    if(ch >= 'A' && ch <= 'Z'){
        printf("UPPER CASE !!");
    }
     else if(ch >= 'a' && ch <= 'z'){
        printf("lower CASE !!");
    }
    else{
        printf("alag parjati");
    }
    return 0;
}