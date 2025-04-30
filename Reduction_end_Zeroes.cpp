#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* code to Remove all zeroes from all the inputted numbers
	eg. 12300 ----> 123
		0012300 ---> 123
*/

char* check_number(char *number){
	int len = strlen(number);
	
	while(len > 1 && number[len-1] == 48){
		number[len-1] = '\0';
		len--;
	}
	int start = 0;
	
	while(number[start] == 48){
		start++;
	}
	if(number[start] == '\0')
		return number;

	return number+start;
}
int main(){
	char* number;
	int ch = 1;
	number = (char*)malloc(100*sizeof(char));
	if(!number){
		perror("\033[0mMemory allocation failed!\033[31m");
		exit(EXIT_FAILURE);	
	}
	while(ch == 1){
	printf("Please enter the number:");
	scanf("%s", number);
	char* mod_number = check_number(number);
	printf("After removing zeroes:%s",mod_number);
	printf("\nWant to check another number?\n1.Yes\n2.No\nEnter your choice: ");
	scanf("%d",&ch);
	}
	free(number);
	return 0;
}
