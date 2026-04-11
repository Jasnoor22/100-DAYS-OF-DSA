// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);
    struct Queue* q = createQueue();
    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "enqueue") == 0) {
            int value;
            scanf("%d", &value);
            enqueue(q, value);
        } else if (strcmp(operation, "dequeue") == 0) {
            int result = dequeue(q);
            printf("%d\n", result);
        }
    }
    return 0;
}                                                                                   