#include<stdio.h>

int main(void){
    register int*ptr;
    int a = 10;
    ptr = &a;
    {
        //register int*ptr;
        int b=5;
        ptr = &b;
        printf("Block1:%d",*ptr);
    }
    printf("\nIn main:%d",*ptr);
    return 0;
}