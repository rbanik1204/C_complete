#include <stdio.h>

int check_number(int num) {
    while (num % 10 == 0 && num != 0) {
        num /= 10;
    }
    return num;
}

int main() {
    int num, choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        int result = check_number(num);
        printf("Number after removing trailing zeroes: %d\n", result);

        printf("Want to check another number?\n1. Yes\n2. No\n");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}

