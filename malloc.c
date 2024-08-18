#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void isort(int *p,int n){
    for(int i = 1;i<n;i++){
        int key ;
        key = p[i];
        int j = i-1;
        while(j>=0 && p[j]>key){
            swap(&p[j],&p[j+1]);
            j--;
        }
    }
}

int main(){
    int n,i,sum = 0,*p;
    printf("enter the amount of space that much you want : ");
    scanf("%d",&n);
    p = (int*)malloc(n*(sizeof(int)));
    if(p == NULL){
        printf("ERROR ! memeory not allocated !!!!!!!11");
        exit(0);
    }
    for(i = 0;i<n;i++){
        scanf("%d",p+i);
        sum += *(p+i);
    }
    printf("sum is : %d\n",sum);
    isort(p,n);
     printf("sorted array is : ");
    for(int i = 0;i<n;i++){
        printf("%d ",*(p+i));
    }
    free(p);
    return 0;
}