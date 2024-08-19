#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a,b,c;
    printf("enter the coefficients of quadratic : ");
    scanf("%d%d%d",&a,&b,&c);

    int discri = b*b - 4*a*c;
    if(discri> 0){
        printf("roots are real!!!\n ");
        int root1 =  (-b+sqrt(discri))/(2*a);
        int root2 =  (-b-sqrt(discri))/(2*a);
        printf("root1 and root 2 are %d,%d respectivily ",root1,root2);
    }
    else if(discri == 0){
        printf("roots are real and equal !!\n");
        int root1 =  (-b+sqrt(discri))/(2*a);
        int root2 =  (-b-sqrt(discri))/(2*a);
        printf("root1 and root2 are %d,%d respectivily ",root1,root2);
    }
    else{
        printf("roots are imaginary !!");
    }

    return 0;
}