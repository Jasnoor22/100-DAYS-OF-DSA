// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }
    heap[size] = value;
    int i = size;
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    size++;
}

int extractMin() {
    if (size == 0) {
        printf("Heap Underflow\n");
        return -1;
    }
    int min = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (i * 2 + 1 < size) {
        int child = i * 2 + 1;
        if (child + 1 < size && heap[child + 1] < heap[child]) {
            child++;
        }
        if (heap[i] <= heap[child]) break;
        int temp = heap[i];
        heap[i] = heap[child];
        heap[child] = temp;
        i = child;
    }
    return min;
}

int peek() {
    if (size == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    return heap[0];
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
        } else if (strcmp(operation, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}
