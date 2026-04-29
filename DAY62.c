#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Step 1: Create adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* size = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int)); // max possible
    }

    // Step 2: Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        adj[u][size[u]++] = v;

        // For undirected graph:
        adj[v][size[v]++] = u;
    }

    // Step 3: Print adjacency list
    for(int i = 0; i < n; i++) {
        printf("%d: ", i);
        for(int j = 0; j < size[i]; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
