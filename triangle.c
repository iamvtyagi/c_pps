#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a ,b,c;
    printf("enter the sides of triangle : ");
    scanf("%d%d%d",&a,&b,&c);
    if( a+b > c || b+c > a || c+a>b){
        printf("valid triangle\n ");
        if((a== b) || (b == c)){
            printf("triangle is equilateral");
        }
        else if((a != b) || (b!= c)){
            printf("scelene");
        }
        else if(((a = b)&& (b!= c)) || ((b = c)&& (c!= a)) || ((c = a)&& (b!= a))){
            printf("isoscales");
        }
        else{
            printf("right angle triangle");
        }
    }
    else{
        printf("invalid triangle !!");
    }

    return 0;
}