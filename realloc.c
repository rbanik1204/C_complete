#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main(void){
    int *ptr = NULL,*ptr1 =NULL;
    int i,n;
    printf("Enter heap size no:");
    scanf("%d",&n);
    ptr = (int*)malloc((n-3)*sizeof(int));
    if(!ptr){
        printf("Error allocation:%s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("Assign data:\n");
    for(i=0;i<n-3;i++)scanf("%d",ptr+i);
    printf("Entered data:");
    for(i=0;i<n-3;i++)printf("%d\t",*(ptr+i));printf("\n");
    printf("Change %d to:%d\n",n-3,n);
    ptr1 = realloc(ptr,n*sizeof(int));
    printf("Copied data:");
    for(i=0;i<n;i++)printf("%d\t",*(ptr+i));printf("\n");
    printf("previous base address:%p\nCurrent base address:%p",ptr,ptr1);
}