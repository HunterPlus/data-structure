#include <stdio.h>
#define V 9

void dfs (int g[V][V], int start)
{
    int stack[V] = {0};
    int top = -1;
    
    int visited[V] = {0};
    int u, v;
   
    stack[++top] = start;
    
    while (top >= 0)
    {
        u = stack[top--];
        if (!visited[u])
        {
            visited[u] = 1;
            printf("vertex %d\n", u);
        }
        
        for (v = V-1; v >= 0; v--)
            if (!visited[v] && g[u][v])
                stack[++top] = v;
    }
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
                        
    dfs(graph, 3);

    return 0;
}
