#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ASK_SIZE(msg,SIZE) \
(printf("%s",msg),scanf("%d",&SIZE))
#define MAX 100
int dp[MAX][MAX];
int k[MAX][MAX];
void init_dp(int N){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			*(*(dp+i)+j) = -1;
}
int MatrixMultiplication(int *array,int i,int j){
	if(dp[i][j] != -1) return dp[i][j];
	if(i == j){
		dp[i][j] = 0;
		k[i][j] = 0;
		return dp[i][j];
	}
	int mini = INT_MAX;
	static int steps;
	for(int l=i;l<j;l++){
		steps = MatrixMultiplication(array,i,l) + MatrixMultiplication(array,l+1,j)+array[i-1]*array[l]*array[j];
		//steps = MatrixMultiplication(array,i+1,l-1)+MatrixMultiplication(array,l,j)+array[i]*array[l-1]*array[j];
		if(steps<mini) {
		mini = steps;
		k[i][j] = l;
	    }
	}
	return dp[i][j] = mini;
}
void parenthesization(char name,int i,int j){
	if(i == j){
		printf("%c",name+(i-1));
		return;
	}
	printf("(");
	parenthesization(name,i,k[i][j]);
	parenthesization(name,k[i][j]+1,j);
	printf(")");
}
int main(void){
	int SIZE;
	ASK_SIZE("Enter number of dimensions:",SIZE);
	int *array = (int*)realloc(NULL,SIZE*sizeof(int));
	printf("Enter the dimensions:");
	for(int i=0;i<SIZE;i++)scanf("%d",array+i);
	init_dp(SIZE);
	int min_mul = MatrixMultiplication(array,1,SIZE-1);
	printf("Number of minimum mul:%d",min_mul);
	parenthesization('A',1,SIZE-1);
	return 0;
}
