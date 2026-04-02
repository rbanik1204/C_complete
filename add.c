#include<stdio.h>
#include<conio.h>
void main(void){
    int i1,i2;
    puts("Data");
    scanf("%d %d",&i1,&i2);
    int r = i1+i2;
    printf("Sum of %d & %d:%d",i1,i2,r);
    getch();
}