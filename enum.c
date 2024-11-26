#include<stdio.h>
#include<stdlib.h>
#include<math.h>

      enum week{sun,mon,tue,wed,thu,fri,sat};
      enum week{sun=2,mon,tue,wed,thu,fri,sat};
int main(){

     enum week day= wed ;
     day = fri;
     printf("%d\n",day);
     for(int i = sun;i<=sat;i++){
        printf("%d ",i);
     }
    return 0;
}