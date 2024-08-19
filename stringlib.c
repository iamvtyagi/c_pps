#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
   char name[10];
   gets(name);
   char name2[] = "tushar";
//    int n  = strlen(name);
     strcpy(name,name2);
//    printf("%d",strcpy(name,name2));
   int n  = strlen(name);
   for(int i = 0;i<n;i++){
    printf("%c",name[i]);
   }
   
    return 0;
}