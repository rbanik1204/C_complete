#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isTidy(int num) {
    char str[12];  
    sprintf(str, "%d", num);  

    for (int i = 0; i < strlen(str) - 1; i++) {
        if (str[i] > str[i + 1]) {
            return false;
        }
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

