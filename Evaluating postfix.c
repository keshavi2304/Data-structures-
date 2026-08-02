#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include <ctype.h>     /* required for isdigit() */

#define MAX 50

int stackArr[MAX];
int top = -1;

/* ---------- Stack functions ---------- */
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stackArr[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stackArr[top--];
}

/* ---------- Calculation function ---------- */
int cal(char op, int op1, int op2) {
    int r;
    switch (op) {
        case '+': r = op1 + op2; break;
        case '-': r = op1 - op2; break;
        case '*': r = op1 * op2; break;
        case '/': r = op1 / op2; break;
        case '$': r =(int)pow(op1, op2); break;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
    return r;
}
/* ---------- Main ---------- */
int main() {
    char post[MAX];
    int op1, op2, r, i = 0;

    printf("Enter expression: ");
    fgets(post, MAX, stdin);

    /* remove trailing newline left by fgets */
    post[strcspn(post, "\n")] = '\0';

    while (post[i] != '\0') {
        if (isdigit(post[i])) {
            push(post[i] - '0');       /* char '0'..'9' -> int value */
        }
        else {
            op2 = pop();
            op1 = pop();
            r = cal(post[i], op1, op2);
            push(r);
        }
        i++;
    }

    r = pop();
    printf("Result = %d\n", r);

    return 0;
}

