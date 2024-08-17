#include<stdio.h>

void binarySearch(int n,int *arr,int t){
         int s = 0,e = n-1;
         int mid = 0;
     int found = 0;
     while(s<=e){
            mid = s + (e-s)/2;
            if(arr[mid]>t){
                e= mid-1;
            }
            else if(arr[mid]<t){
                s = mid+1;
            }
            else{
                printf("element is found at index %d",mid);
                found = 1;
                break;
            }
        }
        if( found == 0){
            printf("element is not present");
        }
}

void linerSearch(int *n,int *arr,int *t){
    int found = 0;
    for(int i = 0;i< *n;i++){
        if(arr[i]== *t){
            printf("found at %d",i);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("not present");
    }
}

int main(){
     int n;
     printf("enter the value of n : ");
     scanf("%d",&n);
      int arr[n];
     printf("enter the values of arr");
     for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
     }

     int t;
     printf("enter the value of target");
     scanf("%d",&t);

     binarySearch(n,arr,t);

    //  linerSearch(&n, arr,&t);




     

    return 0;
}

// tc = O(log n)