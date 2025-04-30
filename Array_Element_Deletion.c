#include<stdio.h>
#include<stdlib.h>
#define ASK_SIZE(msg, SIZE) \
    (printf("%s", msg),scanf("%d",&SIZE))
int** Dynamic_1D_array(int SIZE){
    int **array = (int**)malloc(SIZE * sizeof(int*));
    for(int i = 0;i<SIZE;i++){
        array[i] = (int*)malloc(sizeof(int));
    }
    for(int i = 0;i<SIZE;i++)
        scanf("%d",array[i]);
    return array;
}
int main(void){
    int SIZE;
    ASK_SIZE("Enter Size of array:",SIZE);
    int **array = Dynamic_1D_array(SIZE);
    if(array != NULL)
        printf("Array elements:");
    for(int i = 0;i<SIZE;i++)
        printf("%d\t",*array[i]);
    for(int i = 0;i<SIZE;i++)
        free(array[i]);
    free(array);
}