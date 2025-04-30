#include<stdio.h>
#include<stdlib.h>

void main(){
    char ch;
    char str[50];
    FILE *file = NULL;
    file =fopen("abc.txt","r+");
    ch = fgetc(file);
    printf("%c",ch);
    fseek(file,0,SEEK_SET);
    ch = fgetc(file);
    printf("\n%c",ch);
    while(!feof(file)){
        //fgets(str,5,file);
        fscanf(file,"%s",str);
        printf("\n%s",str);
    }
    rewind(file);
    while(!feof(file)){
        //fgets(str,5,file);
        fscanf(file,"%s",str);
        printf("\n%s",str);
    }
    fclose(file);
}