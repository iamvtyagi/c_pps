#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=  *b;
    *b = temp;
    // printf("value of a and b after swapping is %d and %d\n", *a,*b);
}

int main(){
     int arr[10] ={1,2,3,4,5,6,7,8,9,4};
     for(int i = 0,j = 9; (i<=5,j>=5);i++,j--){
        swap(&arr[i],&arr[j]);
     }
     printf("reverse array is : ");
     for(int i = 0;i<10;i++){
        printf("%d ", arr[i]);
     }
    return 0;
}