#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a stack structure
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        return '\0';  // Return null character for empty stack
    } else {
        return stack[top--];
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char ch, x;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (precedence(ch) <= precedence(stack[top]) && top != -1) {
                x = pop();
                postfix[j++] = x;
            }
            push(ch);
        }
    }

    while (top != -1) {
        x = pop();
        postfix[j++] = x;
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
