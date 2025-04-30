#include<stdio.h>
#include<stdlib.h>

void main(){
    char ch;
    char str[50];
    FILE *fp = NULL;
    fp = fopen("abc.txt","r+");
    while(!feof(fp)){
        ch = fgetc(fp);
        printf("%c",ch);
    }
    rewind(fp);
    fclose(fp);
}