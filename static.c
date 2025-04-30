#include<stdio.h>
void display(void);
int main(void){
    display();
    display();
    return 0;
}
void display(){
    static int x;
    x +=10;
    printf("x = %d\n",x);
}
// Life time of static s.class is thoroughout the program  