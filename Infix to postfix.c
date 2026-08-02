#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Return precedence of operators
int precedence(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {

        // If operand, add to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If '(', push to stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If ')', pop until '('
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
