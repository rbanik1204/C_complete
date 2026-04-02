#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}NODE;
NODE* head = NULL;

NODE* createNode(int val){
    NODE* newnode = (NODE*) malloc(sizeof(NODE));
    (*newnode).data = val;
    (*newnode).next = NULL;
    return newnode;
}
void traverse(NODE* start){
    printf("Final LL:");
    while(start){
        printf("%d ",(*start).data);
        start = start->next;
    }
}
int main(void){
    int n,val;
    NODE *newnode,*temp;
    newnode = temp = NULL;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    while(n--){
        printf("Enter %d node data:",n);
        scanf("%d",&val);
        newnode = createNode(val);
        if(!newnode){
            perror("ERROR!");
            exit(EXIT_FAILURE);
        }
        if(!head){
            head = temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    traverse(head);
    while(head){
        temp = head->next;
        free(head);
        head = temp;
    }
}