#include<stdio.h>
#include<stdlib.h>
#define ASK_SIZE(msg, SIZE)\
	(printf("%s", msg), scanf("%d", SIZE))

int list_length(void);
typedef struct node{
	int data;
	struct node *prev,*next;
}NODE;
NODE* head = NULL,*tail = NULL;

NODE* createnode(int X){
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = X;
	newnode->prev = newnode->next = NULL;
	return newnode;
}


void insert_end(int x){
	if(!head){
		head = tail = createnode(x);
		head->prev = head->next = head;
	}
	else{
		tail->next = createnode(x);
		tail->next->prev = tail;
		tail = tail->next;
		tail->next = head;
		head->prev = tail;
	}
	printf("Inserted->%d\n",tail->data);
	
}

void insert_front(int x){
	if(!head){
		insert_end(x);
	}
	else{
		head->prev = createnode(x);
		tail->next = head->prev;
		head->prev->next = head;
		head = head->prev;
		head->prev = tail;
	}
	printf("Inserted->%d\n",head->data);
}
void insert_at_pos(int x,int pos){
	NODE *newnode = createnode(x);
	if(pos<0 || pos>list_length()+1){
		printf("Invalid Position!\n");
		return;
	}
	else if(!head){
		insert_end(x);
		return;	
	}
	else{
		NODE* temp = head;
		for(int i = 1;i< pos;i++){
			temp = temp->next;
		}
		newnode->prev = temp->prev;
		newnode->next = temp;
		temp->prev->next = newnode;
		temp->prev = newnode;
	}
	printf("Inserted->%d\n",newnode->data);
}

void display(){
	if(!head){
		printf("Empty Linked list!\n");
	}
	else{
		NODE* temp = head;
		printf("Following inserted Data:\n");
		while(temp->next != head){
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("%d\n",temp->data);
	}
}
int list_length(void){
	int count = 0;
	NODE* temp = head;
	while(temp->next != head){
		count++;
		temp = temp->next;
	}
	count++;
	return count;
}
int main(){
	int choice,ch = 1,data,pos;
	while(ch){
	printf("Following Menu:\n1.Insert at End\n2.Insert at Beginning\n3.Insert at position\n4.Display\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter data:");
			scanf("%d",&data);
			insert_end(data);
			break;
		case 2:
			printf("Enter data:");
			scanf("%d",&data);
			insert_front(data);
			break;
		case 3:
			printf("Enter data:");
			scanf("%d",&data);
			printf("Enter insertion position:");
			scanf("%d",&pos);
			insert_at_pos(data,pos);
			break;
		case 4:
			display();
			break;
		default:
			printf("Enter Valid Choice!\n");
	}
	printf("Want to Continue?\n1.Yes\n2.No\nEnter your choice:");
	scanf("%d",&ch);
	}
}
