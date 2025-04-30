#include <stdio.h>
#include <stdbool.h>

bool check_num(int *num) {
    int original = *num;
    while (*num % 10 == 0 && *num != 0) {
        *num /= 10;
    }
    return original != *num;
}

int main() {
    int num, choice;
    bool modified;
    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        modified = check_num(&num);

        printf("Number after removing ending zeroes: %d\n", num);

        if (modified) {
            printf("The number had ending zeroes and was modified.\n");
        } else {
            printf("The number had no ending zeroes.\n");
        }

        printf("Want to check another number?\n1. Yes\n2. No\n");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}

