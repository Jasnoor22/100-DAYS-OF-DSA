// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printCircularList(struct Node* head) {
    if (head == NULL) return;

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    int n;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    // Make it circular
    if (tail != NULL) {
        tail->next = head;
    }

    // Print circular list
    printCircularList(head);

    return 0;
}