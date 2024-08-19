#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if(argc == 2){
        printf("the argument supplied is %s\n",argv[1]);
    }
        else if(argc > 2){
            printf("too many argumentssupplied.\n");
        }
        else{
            printf("one argument expected.\n");
        }
    return 0;
}