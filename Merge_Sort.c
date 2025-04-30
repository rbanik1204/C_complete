#include<stdio.h>
#include<stdlib.h>
#define ASK_SIZE(msg, SIZE) \
((printf("%s",msg)),scanf("%d",&SIZE))
int main(){
    int SIZE,*array;
    ASK_SIZE("Please Enter the Size of array:",SIZE);
    array = (int*)malloc(SIZE * sizeof(int));
    for(int i = 0;i<SIZE;i++){scanf("%i",array+i);}
}