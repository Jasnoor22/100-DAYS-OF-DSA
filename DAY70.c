#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, struct Edge edges[], int source) {
    int dist[MAX];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    // Step 2: Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE WEIGHT CYCLE DETECTED\n");
            return;
        }
    }

    // Step 4: Print distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanFord(V, E, edges, source);

    return 0;
}
