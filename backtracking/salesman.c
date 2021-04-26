#include <stdio.h>
#include <limits.h>
#define V 4

int min (int a, int b) { return (a < b)? a : b; }

void tsputil (int graph[V][V], int v[], int pos, int count, int cost, int *ans)
{
    if (count == V && graph[pos][0])
    {
        *ans = min(*ans, cost + graph[pos][0]);
        return ;
    }
    for (int i = 0; i < V; i++)
    {
        if (!v[i] && graph[pos][i])
        {
            v[i] = 1;
            tsputil(graph, v, i, count+1, cost+graph[pos][i], ans);
            
            v[i] = 0;
        }
    }
    
}
void tsp (int graph[V][V])
{
    int v[V] = { 0 };
    v[0] = 1;
    int ans = INT_MAX;
    
    tsputil(graph, v, 0, 1, 0, &ans);
    
    printf("Sales Man minimum: %d\n", ans);
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
