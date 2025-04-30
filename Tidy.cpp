#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// Code for Non decreasing number(Tidy number)

bool check_Tidy(char *number){
	for(int i = 0;i<strlen(number)-1;i++){
	if(number[i]<number[i+1]){
		continue;
	    }
	else{
		return false;
	    }
	}
	return true;
}
int main(){
	char *number;
	int ch = 1;
	bool val;
	number = (char*)malloc(100 *sizeof(char));
	if(!number){
		perror("Memory allocation failed!");
		exit(EXIT_FAILURE);
	}
	while(ch == 1){
	printf("Please enter the number:");
	scanf("%s",number);
	val = check_Tidy(number);
	if (val)
		printf("Given number is a Tidy number!\n");
	else
		printf("Given number is not a Tidy number!\n");
	printf("Want to check another number?\n1.Yes\n2.No\nEnter your choice: ");
	scanf("%d",&ch);
	}
	free(number);
}
