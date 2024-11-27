#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ssort(int arr[],int n){
    
    for(int i = 0;i<n-1;i++){
         int min_idx = i;
    for(int j = i+1;j<n;j++){
        if(arr[j]<arr[min_idx]){
             min_idx = j;
        }
    }
    swap(&arr[i],&arr[min_idx]);
  }


}
// jo hamara sabse chhota element hai usko sabse left mei puchaa dunga

int main(){
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the array elements : ");
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    ssort(arr,n);
    printf("the sorted array is : ");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// worst best avg tc- O(n*n)
// space complexity- O(1)