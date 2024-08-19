#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n1,m1,n2,m2;
    printf("enter the row than col of matrix1 : ");
    scanf("%d%d",&n1,&m1);
    printf("enter the row and col of matrix 2 : ");
    scanf("%d%d",&n2,&m2);
    if(n2 != m1){
        printf("matrix mul is not possible !!");
        exit(0);
    }
    int mat1[n1][m1];
    int mat2[n2][m2];
    int mat3[n1][m2];
    printf("enter the values of mat1 : ");
    for(int i = 0;i<n1;i++){
        for(int j = 0;j<m1;j++){
             scanf("%d",&mat1[i][j]);
        }
    }
    printf("enter the values of mat2 : ");
    for(int i = 0;i<n2;i++){
        for(int j = 0;j<m2;j++){
             scanf("%d",&mat2[i][j]);
        }
    }  
    // for(int i =0;i<n1;i++){
    //     for(int j= 0;j<m2;j++){
          
    //     }
    // } 
    for(int i = 0;i<n1;i++){
        for(int j = 0;j<m2;j++){
             mat3[i][j]=0;
            for(int k = 0;k<m1;k++){
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    } 
    for(int i =0;i<n1;i++){
        for(int j= 0;j<m2;j++){
            printf("%d ",mat3[i][j]);
        }
    } 
    return 0;
} 