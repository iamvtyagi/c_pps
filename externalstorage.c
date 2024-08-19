#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

extern int a = 7;

void fnc(){
    printf("external variablel is : %d", a );
}


int main(){
      fnc();
    return 0;
}