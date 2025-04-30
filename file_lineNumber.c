#include<stdio.h>
#include<stdlib.h>

void main(){
    FILE *fp = NULL;
    char ch;
    fp =fopen("abc.txt","r");
    int count = 1;
    int char_count = 0;
    while((ch=fgetc(fp))!=EOF){
        if(ch == '\n')
            count++;
        char_count++;
    }
    fclose(fp);
    printf("%d %d",count,char_count);
}