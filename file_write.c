#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
    char ch;
    FILE *fp = NULL;
    fp = fopen("abc.txt","w");
    printf("Enter the character:");
    ch = getchar();
    fputc(ch,fp);
    fputs(" Hello, Im Ratul!",fp);
    fclose(fp);
}