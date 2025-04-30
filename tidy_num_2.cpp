#include <stdio.h>
#include <stdbool.h>

bool isTidy(int num) {
    int prevDigit = 10;  

    while (num > 0) {
        int currentDigit = num % 10;
        if (currentDigit > prevDigit) {
            return false;
        }
        prevDigit = currentDigit;
        num /= 10;
    }
    return true;
}

int main() {
    int num, choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (isTidy(num)) {
            printf("The number is tidy.\n");
        } else {
            printf("The number is not tidy.\n");
        }

        printf("Want to check another number?\n1. Yes\n2. No\n");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}

