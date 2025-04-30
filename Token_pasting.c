#include<stdio.h>
#define tokenpaster(n) printf("\nValue = %d",token##n); // This statement is a token replacement statement

int main(){
    token5 = 100;
    tokenpaster(5)
    return 0;
}
// Token pasting Operator(##)
// This Operator use to Concatenate two Tokens that are available in mactro in here token5 and n