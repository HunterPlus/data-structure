#include <stdio.h>
#include <limits.h>

#define V 5

int min (int w[], int mst[])
{
    int t = INT_MAX;
    int idx;
    
    for (int v = 0; v < V; v++)
        if (mst[v] == 0 && w[v] < t)
            t = w[v], idx = v;
        
    return idx;
}

void printMST(int path[], int g[V][V])
{
    printf("Edge \tWeight\n");
    
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", path[i], i, g[i][path[i]]);    
}

void primMST (int g[V][V])
{
    int path[V], w[V], mst[V];
    
    for (int i = 0; i < V; i++)
        w[i] = INT_MAX, mst[i] = 0;
        
    w[0] = 0;
    path[0] = -1;
    
    for (int count = 0; count < V-1; count++)
    {
        int u = min(w, mst);
        mst[u] = 1;
        
        for (int v = 0; v < V; v++)
            if (g[u][v] && mst[v]==0 && g[u][v] < w[v])
                path[v] = u, w[v] = g[u][v];     
    }
    
    printMST(path, g);
}

int main()
{
    /* 
        2    3
    (0)--(1)--(2)
    |    / \   |
   6| 8/    \5 |7
    | /      \ |
    (3)-------(4)
          9         */
  int graph[V][V] = { { 0, 2, 0, 6, 0 },
                      { 2, 0, 3, 8, 5 },
                      { 0, 3, 0, 0, 7 },
                      { 6, 8, 0, 0, 9 },
                      { 0, 5, 7, 9, 0 } };
                        
    primMST(graph);

    return 0;
}
