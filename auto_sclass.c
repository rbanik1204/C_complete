#include<stdio.h>
auto int x =15;
int main(){
    //auto int x = 10;
    {
        int x =20;
        printf("Block1:%d\n",x);
    }
    {
        printf("Block2:%d\n",x++);
    }
    printf("In main:%d",x);
    return 0;
}