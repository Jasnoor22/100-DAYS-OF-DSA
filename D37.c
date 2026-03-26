// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    int i = size - 1;
    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = value;
    size++;
}

int delete() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    return pq[--size];
}

int peek() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return pq[size - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            int value;
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(operation, "delete") == 0) {
            printf("%d\n", delete());
        } else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}
