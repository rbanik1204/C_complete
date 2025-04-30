#include<stdio.h>

int main(){
    int i,j,count,n;
    scanf("%d",&n);
    int start = 0;
    int end = 2*n-2;
    int array[2*n-1][2*n-1];
    for(count=n;count>0;count--){
       for(i=start;i<=end;i++){
           for(j=start;j<=end;j++){
                if(i==start || i == end || j==start || j == end)
                    array[i][j]=count;
           }
       }
       start++;
       end--;
    }
    for(int k=0;k<2*n-1;k++){
        for(int l=0;l<2*n-1;l++){
            printf("%d",array[k][l]);
        }
        printf("\n");
    }
}