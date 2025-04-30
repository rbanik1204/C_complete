#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *ptr = NULL,n =5;
    ptr = calloc(5,sizeof(int));
    //printf("Heap allocated memory size_no:");
    //scanf("n:%d",&n); // "%[^\n] keeps reading until newline
    //ptr = (int*) malloc(n * sizeof(int));
    printf("Enter values:");
    for(int i=0;i<n-2;i++)scanf("%d",ptr+i);
    printf("Entered values are:");
    for(int i=0;i<n;i++)printf("%d\t",*(ptr+i));
}