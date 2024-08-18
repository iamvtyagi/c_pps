#include "stdio.h"

int main(){

          // simple pointer 

      //  int a = 34;
      //  int *p = &a;
      // //  printf("%u\n",*p);
      //  printf("%d\n",p);
      //  p++;
      // //  *p = *p + 3;
      // printf("%u\n",*p);
      //  printf("%d\n",p);

      //void pointer

      // int c = 5;
      // void *v = &c;
      // printf("%u\n",*(int*)v);
      // printf("%d\n",v);
      // printf("%d\n",(int*)v);        //both are same

      // int *t = (int*)v;
      // // void pointer does not support pointer arithmetic directly thats why we do this
      // printf("%d\n",t);
      // t++;
      // printf("%d\n",t);


      int *n;
      int r = 5;
      n = &r;
      printf("%u",*n);

      return 0;
}