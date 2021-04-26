#include <stdio.h>
#include <limits.h>
#define V 4

int tsputil (int graph[V][V], int v[], int path[],
                int pos, int count, int cost, int *ans)
{
    if (count == V-1 && graph[pos][0])
    {
        if (*ans > cost + graph[pos][0])
        {
            *ans = cost + graph[pos][0];
            path[count] = pos;
            return 1;
        }
        return 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (!v[i] && graph[pos][i])
        {
            v[i] = 1;
            
            if (tsputil(graph, v, path, i, count+1, cost+graph[pos][i], ans))
            {
                path[count] = pos;
                v[i] = 0;
                return 1;
            }
            
            v[i] = 0;
        }
    }
    return 0;
}
void tsp (int graph[V][V])
{
    int v[V] = { 0 };
    v[0] = 1;
    
    int path[V] = { 0 };
    path[0] = 0;
    
    int ans = INT_MAX;
    
    for (int i = 0; i < V; i++)
    {
        if (!v[i] && graph[0][i])
        {
            v[i] = 1;
            tsputil(graph, v, path, i, 1, graph[0][i], &ans);
            
            v[i] = 0;
        }
    }
    
    printf("Sales Man minimum: %d\n", ans);
    for (int i = 0; i < V; i++)
        printf("%2d ", path[i]);
}

int main()
{
    int graph[][V] = {
                        { 0, 10, 15, 20 },
                        { 10, 0, 35, 25 },
                        { 15, 35, 0, 30 },
                        { 20, 25, 30, 0 }
                     };
                     
    tsp(graph);

    return 0;
}
