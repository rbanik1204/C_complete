#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define N 4
char board[N][N][3];
void print_Board(){
    for(int i=0;i<N;i++){
        for (int j = 0; j < N; j++)
        {
            printf("%s\t",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int row,int col){
    register int i=0,j=0;
    for(j=0;j<N;j++){
        if(!strncmp(board[row][j],"Q",1))return false;
    }
    for(i=0;i<N;i++){
        if(!strncmp(board[i][col],"Q",1))return false;
    }
    for(i=row,j=col;i>=0,j>=0;i--,j--){
        if(!strncmp(board[i][j],"Q",1))return false;
    }
    for(i=row,j=col;i>=0,j<N;i--,j++){
        if(!strncmp(board[i][j],"Q",1))return false;
    }
    return true;
}
void nqueens(int row){
    if(row == N){
        print_Board();
        printf("All queens are succesfully placed!\n");
        return;
    }
    for(int j=0;j<N;j++){
        if(isSafe(row,j)){
            sprintf(board[row][j],"Q%d",j+1);
            nqueens(row+1);
            strcpy(board[row][j],"."); // Backtrack
        }
    }
}
int main(void){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            strcpy(board[i][j],".");
    
    nqueens(0);
}