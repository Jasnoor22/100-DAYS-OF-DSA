// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedHead = NULL;
    struct Node* mergedTail = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (list1->data < list2->data) {
            newNode->data = list1->data;
            list1 = list1->next;
        } else {
            newNode->data = list2->data;
            list2 = list2->next;
        }
        newNode->next = NULL;

        if (mergedHead == NULL) {
            mergedHead = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
    }

    // Append any remaining nodes from either list
    while (list1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = list1->data;
        newNode->next = NULL;
        if (mergedHead == NULL) {
            mergedHead = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
        list1 = list1->next;
    }

    while (list2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = list2->data;
        newNode->next = NULL;
        if (mergedHead == NULL) {
            mergedHead = newNode;
            mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
        list2 = list2->next;
    }

    return mergedHead;
}

int main() {
    int n, m;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Read first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = list1;
        list1 = newNode;
    }

    // Read second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = list2;
        list2 = newNode;
    }

    // Merge the two lists
    struct Node* mergedList = mergeSortedLists(list1, list2);
    printList(mergedList);

    // Free the allocated memory
    struct Node* current = mergedList;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
