#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int i, j;

    // Step 1: Calculate in-degree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Step 2: Push all 0 in-degree nodes into queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    int count = 0;

    // Step 3: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (j = 0; j < n; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int n, i, j;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(n, adj);

    return 0;
}
