#include<stdio.h>
#include<stdlib.h>
#define ASK_SIZE(msg, SIZE) \
    (printf("%s ", msg), scanf("%d", &SIZE))
int* createarray(int SIZE){
    int *array =(int*)malloc(SIZE * sizeof(int));
    printf("Enter values:\n");
    for(int i = 0;i<SIZE;i++){
        scanf("%d",array+i);
    }
    return array;
}
void insert(int *array,int pos,int SIZE){
    if(pos<0){
        printf("Invalid position!\n");
    }
    else{
        array[SIZE] = 0;
        for(int i = SIZE-1;i>=pos-1;i--){
            array[i+1]=array[i];
        }
    }
    printf("Enter Value:");
    scanf("%d",&array[pos-1]);
    printf("Inserted->%d at %d\n",array[pos-1],pos);
        for(int i = 0;i<SIZE-1;i++){
        printf("%d\t",array[i]);
    }printf("\n");
}
void Delete(int *array,int pos,int SIZE){
    if(pos<0){
        printf("Invalid position!\n");
    }
    else{
        array[SIZE] = 0;
        for(int i = pos-1;i<SIZE;i++){
            array[i] = array[i+1];
        }
    }
    printf("Deleted position %d value\n",pos);
    printf("After deletion elements inside array:");
    for(int i = 0;i<SIZE-1;i++){
        printf("%d\t",array[i]);
    }printf("\n");
}
int main(){
    int SIZE,*array,position,ch=1;
    ASK_SIZE("Please enter the size of array:", SIZE);
    array = createarray(SIZE);
    while(ch){
    printf("Following menu:\n1.Insert_at_pos\n2.Delete_from_pos\nEnter your choice:");
    scanf("%d",&ch);
    printf("Enter position:");
    scanf("%d",&position);
    switch(ch){
        case 1:
        insert(array,position,SIZE);
        break;
        case 2:
        Delete(array,position,SIZE);
        default:
            printf("Invalid input!");
    }
    printf("Want to continue?\n1.Yes\n0.No\nEnter choice:");
    scanf("%d",&ch);
    }
}