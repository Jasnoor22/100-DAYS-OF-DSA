#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n, m;

int findMin() {
    int min = INF, index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int source) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 1; count <= n; count++) {
        int u = findMin();

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int source, u, v, w;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;   // remove if directed graph
    }

    scanf("%d", &source);

    dijkstra(source);

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
