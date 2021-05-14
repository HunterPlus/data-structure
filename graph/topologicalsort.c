#include <stdio.h>
#define V 6

void topoutil (int graph[V][V], int u, int visited[], int stack[], int *top)
{
    visited[u] = 1;
    
    for (int v = 0; v < V; v++)
        if (graph[u][v] && !visited[v])
            topoutil(graph, v, visited, stack, top);
    
    stack[++*top] = u;
}
void toposort (int graph[V][V])
{
    int visited[V] = { 0 };
    int stack[V] = { 0 };
    int top = -1;
    
    for (int u = 0; u < V; u++)
        if (visited[u] == 0)
            topoutil(graph, u, visited, stack, &top);
    
    while (top >= 0)
        printf("%d ", stack[top--]);
}
int main()
{
    int graph[V][V] = { {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0} };
    toposort(graph);

    return 0;
}
