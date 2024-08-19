#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    
    int mat1[3][3];
    int mat2[3][3];
    printf("input that matrix you want to transpose : ");
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            scanf("%d",&mat1[i][j]);
    }
    }
    for(int i = 0;i<3;i++){
      for(int j = 0;j<3;j++){
            printf("%d ",mat1[i][j]);
    }
    }
        for(int i = 0;i<3;i++){
      for(int j = 0;j<3;j++){
           mat2[i][j]= mat1[j][i];
    }
    }
     for(int i = 0;i<3;i++){
      for(int j = 0;j<3;j++){
           printf("%d ",mat2[i][j]);
    }
    }
    return 0;
}