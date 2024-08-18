#include<stdio.h>

int swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void isort(int arr[],int n){
    for(int i = 1;i<n;i++){
        int key ;
        key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            swap(&arr[j],&arr[j+1]);
            j--;
        }
    }
}

int main(){
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the array elements : ");
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    isort(arr,n);
    printf("the sorted array is : ");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

//tc for worst and avg = O(n*n)
//best case tc = O(n)
// sc = O(1) 