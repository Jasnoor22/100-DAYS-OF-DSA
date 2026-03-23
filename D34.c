// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    char postfix[100];
    scanf("%s", postfix);

    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            int b = pop();
            int a = pop();
            int result = applyOperator(a, b, postfix[i]);
            push(result);
        }
    }

    printf("%d\n", pop());
    return 0;
}
