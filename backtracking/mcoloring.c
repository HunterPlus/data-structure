#include <stdio.h>

#define V 4

void printarray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
int safe (int graph[V][V], int color[], int v, int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}
int colorutil (int graph[V][V], int color[], int v, int m)
{
    if (v == V)
        return 1;
        
    for (int c = 1; c <= m; c++)
    {
        if (safe(graph, color, v, c))
        {
            color[v] = c;
            if (colorutil(graph, color, v+1, m))
                return 1;
            
            color[v] = 0;
        }
    }
    return 0;
}
int graphcoloring (int graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
    if (colorutil(graph, color, 0, m) == 0)
    {
        printf("Solution does not exist");
        return 0;
    }
    
    printarray(color, V);
    return 0;
}
int main()
{
    int graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3; // Number of colors 1 2 3
    graphcoloring(graph, m);

    return 0;
}
