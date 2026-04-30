#include <stdio.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int selected[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph with INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int edges = 0, totalWeight = 0;

    // Start from node 1
    selected[1] = 1;

    while (edges < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        selected[y] = 1;
        totalWeight += min;
        edges++;
    }

    printf("%d\n", totalWeight);

    return 0;
}
