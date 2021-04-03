#include <stdio.h>
#include <stdlib.h>

#define V 5
int visited[V] = {0};

void dfs (int g[V][V], int u)
{
    visited[u] = 1;
    
    printf("vertex: %d\n", u);
    
    for (int v = 0; v < V; v++)
        if (!visited[v] && g[u][v])
            dfs(g, v);
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 0 },
                        { 0, 5, 7, 0, 0 } };
                        
    dfs(graph, 4);

    return 0;
}
