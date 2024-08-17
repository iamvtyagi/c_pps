// #include "stdio.h"
// #include<stdlib.h>

// int main(){
//     // #define a 10
//     // #define b 50
//     // #if (a>b)
//     //  printf("%d",a+b);
//     //  #elif(a==b)
//     //  printf("%d",a-b);
//     //  #else
//     //  printf("%d",a-b);
//     //  #endif

//     //  int a = 2;
//     //  int *ptr = &a;
//     //   printf("%u",ptr);
//     //  printf("%u\n",*(int*)ptr);
//     // //  (int)ptr++;
//     //  printf("%u",*(int*)ptr);

//     // FILE *fp1;
//     // FILE *fp2;
//     // char ch;
//     // // int nol = 0, not = 0, noc = 0, nos = 0;

//     // fp1 = fopen("hey.txt","r");
//     // if(fp1 == NULL){
//     //     printf("can not open the file\n");
//     //     exit(0);
//     // }
//     //     fp2 = fopen("hello.txt","w");
//     // if(fp2 == NULL){
//     //     printf("can not open the file\n");
//     //     exit(0);
//     // }

//     // while(1){
//     //     ch = fgetc(fp1);
//     //     if(ch == EOF){
//     //         break;
//     //     }
//     //     fputc(ch,fp2);
//     // }
//     // fclose(fp1);
//     // fclose(fp2);
//     int a = 2;
//     void *ptr = (int*)&a;
//     printf("%u", *ptr );
//     return 0;
// }

#include<stdio.h>
// #include<stdlib.h>

int main(){
    int a = 3;
    void *ptr = &a;
    printf("%u",*(int*)ptr);
    getchar();
    return 0;
}