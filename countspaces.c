#include<stdio.h>
#include<stdlib.h>

int main(){
     FILE *fp = fopen("vansh.txt","r");
     int nol = 0,nos= 0,not=0,noc=0;
     char ch;
     while(1){
        ch = fgetc(fp);
        if(ch == EOF){    // EOF = end of file
            break;
        }
       if(ch == ' '){ 
            nos++;
        }
       if(ch == '\n'){ 
            nol++;
        }
       if(ch == '\t'){ 
            not++;
        } 
        else{
             noc++;
        }               
     }
     fclose(fp);
     printf("nos %d\n",nos);
     printf("nol %d\n",nol);
     printf("not %d\n",not);
     printf("noc %d\n",noc);
    return 0;
}