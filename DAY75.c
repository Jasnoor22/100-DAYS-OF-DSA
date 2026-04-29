#include <stdio.h>
#include <stdlib.h>

// Simple hash map using arrays (since C doesn't have built-in hashmap)
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define SIZE 1000

Node* hashTable[SIZE];

// Hash function
int hash(int key) {
    return abs(key) % SIZE;
}

// Insert into hashmap
void insert(int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

// Search in hashmap
int search(int key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -2; // not found
}

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if (sum == 0)
            maxLen = i + 1;

        // Case 2: sum seen before
        int prevIndex = search(sum);
        if (prevIndex != -2) {
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            insert(sum, i);
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of largest subarray with zero sum: %d\n",
           maxLenZeroSum(arr, n));

    return 0;
}
