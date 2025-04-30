#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node *left,*right,*parent;
}ST;
ST *root=NULL,*temp = NULL;
ST* createnode(int val){
    ST* newnode= (ST*) malloc(sizeof(ST));
    newnode->key = val;
    newnode->left = newnode->parent = newnode->right = NULL;
    return newnode;
}
ST* construct_ST(ST* root,int data){
    if(!root){
        root = createnode(data);
        return root;
    }
    else if (data < root->key){
        root->left = createnode(data);
        root = right_rotation(root,root->left); 
    }
    else if(data > root->key){
        root->right = createnode(data);
        root = left_rotation(root,root->right);
    }
    
}
int main(){
    int data;
    printf("Enter the value:");
    scanf("%d",&data);
    root = construct_ST(root,data);
}