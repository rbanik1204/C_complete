#include<stdio.h>

int main(int argc,char const* argv[]){
    printf("The value of argC:%d\n",argc);
    for(int i=0;i<argc;i++)
        printf("%s\n",argv[i]);
}