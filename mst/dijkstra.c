#include <stdio.h>
#include <limits.h>

#define V 9

int min (int d[], int spt[])
{
    int t = INT_MAX, idx;
    
    for (int v = 0; v < V; v++)
        if (spt[v] == 0 && d[v] <= t)
            t = d[v], idx = v;
    
    return idx;
}

void printSPT (int d[])
{
    printf("Vertex \t\t Distance from Source\n");
    
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, d[i]);
}

void dijkstra (int g[V][V], int src)
{
    int d[V], spt[V];
    
    for (int i = 0; i < V; i++)
        d[i] = INT_MAX, spt[i] = 0;
    
    d[src] = 0;
    
    for (int count = 0; count < V-1; count++)
    {
        int u = min(d, spt);
        spt[u] = 1;
        
        for (int v = 0; v < V; v++)
            if (g[u][v] && !spt[v] && d[u] != INT_MAX
                && d[u] + g[u][v] < d[v])
                d[v] = d[u] + g[u][v];
    }
    
    printSPT(d);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
    dijkstra(graph, 0);

    return 0;
}
