#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h> // Include for strlen function
#define ASK_SIZE(msg, SIZE) \
    (printf("%s", msg), scanf("%d", &SIZE), getchar()) // Buffer has been cleared successfully

int top = -1;
int stack[10];
int SIZE; // Define SIZE globally so it can be used in `push`

void push(int x) {
    if (top == SIZE - 1) { // Fix stack overflow condition
        printf("STACK OVERFLOW!\n");
    } else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    int item;
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; // Return -1 if stack is empty
    } else {
        item = stack[top];
        top--;
    }
    return item;
}

int main() {
    int top1, top2, value, c;
    char val;

    ASK_SIZE("Enter expression length:", SIZE);

    char *exp = (char *)malloc(SIZE * sizeof(char));
    if (exp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the expression: ");
    fgets(exp, SIZE + 1, stdin);

    printf("You entered: %s", exp);

    for (int i = 0; i < strlen(exp); i++) {
        val = exp[i];
        if (isdigit(val)) {
            push(val - '0');
        } else {
            top1 = pop();
            top2 = pop();
            switch (val) {
                case '+':
                    c = top2 + top1;
                    push(c);
                    break;
                case '-':
                    c = top2 - top1;
                    push(c);
                    break;
            }
        }
    }

    value = pop();
    printf("Final result: %d\n", value);

    free(exp); // Free the allocated memory
    return 0;
}

