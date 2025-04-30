#include<stdio.h>
#include<stdlib.h>

void main(){
    char ch;
    char str[50]="Ratul Banik";
    FILE *file = NULL;
    file = fopen("abc.txt","a");
    // fputc('l',file);
    fprintf(file,"%s",str);
    rewind(file);
}