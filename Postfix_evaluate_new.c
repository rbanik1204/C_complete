#include<stdio.h>
#include<stdlib.h>
//Defining macro to ask SIZE of STACK
#define ASK_SIZE(msg, SIZE) \
    (printf("%s",msg),scanf("%d",&SIZE))
int* createSTACK(SIZE){
    int *STACK =(int*)malloc(SIZE*sizeof(int));
    return STACK; 
}
void main(){
    char* POSTFIX =(char*)malloc(20*sizeof(char));
    puts("Please enter the postfix exp:");
    for(int i = 0;i<20;i++){
        scanf("%c",POSTFIX+i);
    }
    for(char i = 0;i<strlen(POSTFIX);i++){
        if(isdigit(POSTFIX[i])){
            push(POSTFIX[i]-'0');
        }
        else{
            Top_element = pop();
            Next_to_Top = pop();
            switch(POSTFIX[i]){
                
            }
        }
    }
}