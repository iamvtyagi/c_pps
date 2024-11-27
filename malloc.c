#include<stdio.h>
#include<stdlib.h>



int main(){
    int n,i,sum = 0,*p;
    printf("enter the amount of space that much you want : ");
    scanf("%d",&n);
    p = (int*)malloc(n*(sizeof(int)));
    if(p == NULL){
        printf("ERROR ! memeory not allocated !!!!!!!11");
        exit(0);
    }
    printf("enter the values of array : ");
    for(i = 0;i<n;i++){
        scanf("%d",p+i);  
        sum += *(p+i); 
    }
    printf("sum is : %d\n",sum);

    free(p);
    return 0;
}