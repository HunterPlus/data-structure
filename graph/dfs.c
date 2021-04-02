#include <stdio.h>
#define V 5

void dfs (int g[V][V], int start)
{
    int stack[V] = {0};
    int top = -1;
    
    int visited[V] = {0};
    int u, v;
    
    visited[start] = 1;
    stack[++top] = start;
    
    while (top >= 0)
    {
        u = stack[top--];
        printf("vertex %d\n", u);
        
        for (v = V-1; v >= 0; v--)
            if (!visited[v] && g[u][v])
                visited[v] = 1, stack[++top] = v;
    }
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 0 },
                        { 0, 5, 7, 0, 0 } };
                        
    dfs(graph, 3);

    return 0;
}
