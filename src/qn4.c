#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int isOperand(char ch) {
    return isalnum(ch);
}

void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void replaceParentheses(char *exp) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

struct Stack {
    int top;
    char items[MAX];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

void push(struct Stack* stack, char item) {
    stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) return '\0';
    return stack->items[stack->top--];
}

char peek(struct Stack* stack) {
    if (stack->top == -1) return '\0';
    return stack->items[stack->top];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void infixToPostfix(char *exp, char *result) {
    struct Stack* stack = createStack();
    int k = 0;
    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];
        if (isOperand(c)) {
            result[k++] = c;
        } else if (c == '(') {
            push(stack, c);
        } else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                result[k++] = pop(stack);
            }
            pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(c)) {
                result[k++] = pop(stack);
            }
            push(stack, c);
        }
    }
    while (!isEmpty(stack)) {
        result[k++] = pop(stack);
    }
    result[k] = '\0';
    free(stack);
}

void infixToPrefix(char *exp, char *result) {
    reverse(exp);
    replaceParentheses(exp);
    infixToPostfix(exp, result);
    reverse(result);
}

int main() {
    char exp[MAX];
    char result[MAX];
    printf("Enter the expression in infix: ");
    scanf("%s", exp);
    infixToPrefix(exp, result);
    printf("Prefix: %s\n", result);
    printf("Submitted By Sijan Panta");
    return 0;
}
