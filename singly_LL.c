#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
    int data;
    struct node* next;
}NODE;
NODE* head = NULL;
int n;
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
void insert(int pos,NODE* start){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    NODE *temp = NULL;
    printf("Enter the data You want to Insert:");
    scanf("%d",&(*newnode).data);
    newnode->next = NULL;
    n = 0;
    while(n!=pos-2 && n>1){
        start =start->next;
    }
    temp = start->next;
    start->next = newnode;
    newnode->next = temp;
}
void deletion(int pos,NODE* start){
    NODE* temp = NULL;
    n=0;
    while(n!=pos-2){
        start = start->next;
    }
    temp = start->next;
    start->next = temp->next;
    // memset(temp,-1,NULL);
    free(temp);
}
int main(void){
    int val,pos;
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
    printf("Enter the position of Insertion:");
    scanf("%d",&pos);
    insert(pos,head);
    traverse(head);
    printf("\nEnter deletion position:");
    scanf("%d",&pos);
    deletion(pos,head);
    traverse(head);
    while(head){
        temp = head->next;
        free(head);
        head = temp;
    }
}