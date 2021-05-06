#include <stdio.h>

#define V 4

void printarray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int graphcoloring (int graph[V][V], int start, int m)
{
    int visited[V];
    int color[V];
    int q[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0, color[i] = 1, q[i] = 0;
    int front, rear;
    front = rear = -1;
    
    int maxcolor = 1;
   
    visited[start] = 1;
    q[++rear] = start;
    
    while (front != rear)
    {
        int v = q[++front];
        for (int i = 0; i < V; i++)
        {
            if (graph[v][i] && color[v] == color[i])
            {
                color[i] += 1;
                maxcolor = (color[i] > maxcolor)? color[i] : maxcolor;
                if (maxcolor > m)
                    return 0;
                if (visited[i] == 0)
                {
                    visited[i] = 1;
                    q[++rear] = i;
                }
            }
        }
    }
    printarray(color, V);
    return 1;
}

int main()
{
    int graph[V][V] = {
        { 0, 1, 0, 1 },
        { 1, 0, 1, 0 },
        { 0, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3; // Number of colors 1 2 3
    graphcoloring(graph, 0, m);

    return 0;
}
