#include<stdio.h>
#define stringize(n)   printf("%s",#n);\
                       printf("\n");
#define String(a,b)   printf(#a"_"#b);
int main(){
    stringize(HELLO);
    String(RATUL,BANIK);
}