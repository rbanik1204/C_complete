#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
void main(){
    int *ptr = NULL,*ptr1 =NULL;
    int i,n;
    printf("Enter heap size no:");
    scanf("%d",&n);
    ptr = (int*)calloc(n,sizeof(int));
    if(!ptr){
        printf("Error allocation:%s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("Assign data:");
    for(i=0;i<n-3;i++)scanf("%d",ptr+i);
    printf("Current values:");
    for(i=0;i<n;i++)printf("%d\t",*(ptr+i));
    printf("\n");
    free(ptr);
    memset(ptr,0,n*sizeof(int));
    for(i=0;i<n;i++)printf("%d\t",*(ptr+i));
    // free(ptr);

}