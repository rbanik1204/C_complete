#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    char ch;
    FILE *fp=NULL;
    char str[50];
    fp=fopen("abc.txt","r");
    if(fp==NULL){
    perror("ERROR!");
    exit(1);
    }
    while(!feof(fp)){
        // ch = fgetc(fp);
        fgets(str,10,fp);
        printf("%s",str);
    }
}