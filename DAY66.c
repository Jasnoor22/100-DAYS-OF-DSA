#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V; // number of vertices

// DFS function to detect cycle
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) { // if edge exists

            // Case 1: Not visited → go deeper
            if (!visited[i]) {
                if (dfs(i))
                    return 1;
            }

            // Case 2: Already in recursion stack → cycle
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0; // backtrack
    return 0;
}

// Function to check cycle
int hasCycle() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize arrays
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    if (hasCycle())
        printf("YES - Cycle exists\n");
    else
        printf("NO - No cycle\n");

    return 0;
}
