#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
#define SIZE 5
int dp[MAX][MAX];
int k[MAX][MAX];
void init_dp(int N) {
for(int i=0;i<N;i++) {
  for(int j=0;j<N;j++) {
  dp[i][j]=-1;
  }
 }
}

int MCM(int*array,int i,int j) {
  if(i==j) 
    return 0;
  if(dp[i][j]!=-1)
    return dp[i][j];
  int mini=INT_MAX;
  static int steps;
  for(int l=i;l<j;l++) {
    steps=MCM(array,i,l) + MCM(array,l+1,j) + array[i-1]*array[l]*array[j];
    if(steps<mini) mini=steps;
  }
  return dp[i][j]=mini;
}

int main()
{
  int *array=(int*)malloc(SIZE*sizeof(int)) ;
  printf("enter dimensions:");
  for(int i=0;i<SIZE;i++) 
   scanf("%d",&array[i]);
  init_dp(SIZE) ;
  int min_mul=MCM(array,1,SIZE-1);
  printf("number of minimum multiplication:%d",min_mul);
}
