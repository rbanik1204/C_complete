#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int key;
    struct node *left,*right;
}BT;
BT* root =NULL;
BT* createnode(int data){
    BT* newnode = (BT*)malloc(sizeof(BT));
    newnode->key = data;
    newnode->left = newnode->right=NULL;
    return newnode;
}
BT* construct_bt(){
    BT* newnode = createnode();
    printf("Enter data(0 for no node):");
    scanf("%d",&newnode->data);
    if(!newnode->data)
        return NULL;
    printf("Left child of %d:\n",newnode->data);
    newnode->left = construct_bt();
    printf("Right child of %d:\n",newnode->data);
    newnode->right = construct_bt();
    return newnode;
}
BT* insertnode(BT* node,int data){
    if(!node)
        return createnode(data);
    else if(data < node->key)
        construct_bt(node->left,data);
    else if(data > node->key)
        construct_bt(node->right,data);
    return node;
}
int main(){
    root = construct_bt();
    construct_bt(root,10)
}