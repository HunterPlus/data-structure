#include <stdio.h>

#define V 5

void bfs (int g[V][V], int start)
{
    int Q[V];
    int front = -1;
    int rear = -1;
    
    int i, vertex;
    int visited[V] = {0};
    
    Q[++rear] = start;
    
    while (front != rear)
    {
        vertex = Q[++front];
        printf("vertex %d\n", vertex);
        visited[vertex] = 1;
        
        for (i = 0; i < V; i++)
            if (visited[i] != 1 && g[vertex][i] != 0)
                Q[++rear] = i;
    }
    
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
                        
    bfs(graph, 2);

    return 0;
}
