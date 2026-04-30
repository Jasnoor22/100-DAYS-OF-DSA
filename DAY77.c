#include <stdio.h>

int graph[100][100], visited[100], n, m;

void dfs(int node)
{
    visited[node] = 1;

    for(int i = 1; i <= n; i++)
    {
        if(graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int u, v;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;   // undirected graph
    }

    dfs(1);   // start from node 1

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");

    return 0;
}
