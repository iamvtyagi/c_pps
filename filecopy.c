#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE  *fp1,*fp2;
    char ch;
    fp1 = fopen("file1.txt","r");
    if(fp1 == NULL){
        printf("file1 not found");
        exit(0);
    }
    fp2 = fopen("file2.txt","w");
    if(fp2 == NULL){
        printf("file2 not found");
        exit(0);
    }   
    while(1){
        ch = fgetc(fp1);
        if(ch == EOF){
            break;
        }
        fputc(ch,fp2);
    } 
    fclose(fp1);
    fclose(fp2);

    printf("file1 is copied to file2");
    return 0;
}