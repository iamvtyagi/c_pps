#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bsort(int arr[],int n){
    
    for(int i = 0;i<n-1;i++){
         int isswap = 0;
    for(int j = 0;j<n-1-i;j++){
        if(arr[j]>arr[j+1]){
            swap(&arr[j],&arr[j+1]);
             isswap = 1;
        }
    }
      if(isswap == 0){
        break;
    }
  }

}


// hame sabse bade element ko array ke last mei phuchana hai 
int main(){
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the array elements : ");
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bsort(arr,n);
    printf("the sorted array is : ");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// worst and average case tc - O(n*n)
//best case tc - O(n)
//sc - O(1)