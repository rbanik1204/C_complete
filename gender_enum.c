#include<stdio.h>
typedef enum gender{WOMEN=60,MEN=45,OTHER=50}g;
const char* ch[] = {
    [60] = "WOMEN",
    [45] = "MEN",
    [50] = "OTHER"
};
int main(void){
    g individual =WOMEN;
    char str[20];
    printf("Corresponding off on purchase:%d",individual);

}