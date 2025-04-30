#include <stdio.h>

void calculate_the_maximum(int n, int k) {
  int var1=0,var2=0,var3=0;
  for(int i = 1;i<=n;i++){
    for(int j = 2;j<=k;j++){
        if(j>i){
            if((i&j) < k && var1<(i&j))
                var1 = i&j;
            if((i|j) < k && var2<(i|j))
                var2 = i|j;
            if((i^j) < k && var3<(i^j))
                var3 = i^j;
        }
    }
  }
  printf("%d\n%d\n%d",var1,var2,var3);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    return 0;
}
