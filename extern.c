#include<stdio.h>
#include"support_extern.c"
extern void sum();
int main(void){
    int x,y;
    printf("values of x and y:");
    scanf("%d %d",&x,&y);
    sum(x,y);
}
