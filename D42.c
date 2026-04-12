// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10
#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int* arr;
    int top;
    int capacity;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to reverse the queue using a stack
void reverseQueue(int* arr, int n) {
    struct Stack* stack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }
    free(stack->arr);
    free(stack);
}

// Main function
int main() {
    int N;
    scanf("%d", &N);
    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    reverseQueue(arr, N);
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
