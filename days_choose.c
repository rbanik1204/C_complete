#include<stdio.h>
typedef enum week_days{SUNDAY=1,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY}days;
int main(void){
    days day1;
    printf("Enter day number:");
    scanf("%d",&day1);
    switch(day1){
        case SUNDAY:
            printf("It is SUNDAY yay!");
            break;
        case MONDAY:
            printf("It is MONDAY");
        case TUESDAY:
            printf("It is TUESDAY");
            break;
        case WEDNESDAY:
            printf("It is WEDNESDAY");
            break;
        case THURSDAY:
            printf("It is THURSDAY");
            break;
        case FRIDAY:
            printf("It is FRIDAY");
            break;
        case SATURDAY:
            printf("It is SATURDAY");
        default:
            printf("Invalid day Number!");
    }
}