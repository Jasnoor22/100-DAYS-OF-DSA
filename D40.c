// Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

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
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    size++;
}

int extractMax() {
    if (size == 0) {
        printf("Heap Underflow\n");
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (i * 2 + 1 < size) {
        int child = i * 2 + 1;
        if (child + 1 < size && heap[child + 1] > heap[child]) {
            child++;
        }
        if (heap[i] >= heap[child]) break;
        int temp = heap[i];
        heap[i] = heap[child];
        heap[child] = temp;
        i = child;
    }
    return max;
}

void heapSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[n - 1 - i] = extractMax();
    }
}

int main() {
    int arr[] = {40, 10, 30, 50, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
