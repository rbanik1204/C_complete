#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void main(){
    int *ptr = NULL;
    int n,i;
    printf("Heap allocated memory size_no:");
    scanf("n:%d",&n); // "%[^\n] keeps reading until newline
    ptr = (int*) malloc(n * sizeof(int));
    printf("Enter values:");
    for(i=0;i<n;i++)scanf("%d",ptr+i);
    printf("Entered values are:");
    for(i=0;i<n;i++)printf("%d\t",*(ptr+i));
}