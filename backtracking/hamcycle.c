#include <stdio.h>
#define V 5
int safe (int vtx, int graph[V][V], int path[], int pos)
{
    if (graph[path[pos-1]][vtx] == 0)
        return 0;
    for (int i = 0; i < pos; i++)
        if (path[i] == vtx)
            return 0;
                
    return 1;
}
int hamcycleutil (int graph[V][V], int path[], int pos)
{
    if (pos == V)
    {
        if (graph[path[pos-1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (safe(i, graph, path, pos))
        {
            path[pos] = i;
            if (hamcycleutil(graph, path, pos+1))
                return 1;
                
            path[pos] = -1;
        }
    }
    return 0;
}
void printsolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
    
    printf(" %d ", path[0]);
    printf("\n");
}
int hamcycle (int graph[V][V])
{
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    
    path[0] = 0;
    if (hamcycleutil(graph, path, 1) == 0)
    {
        printf("\nSolution does not exist");
        return 0;
    }
    printsolution(path);
    return 1;
}
int main()
{
    int graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0},
                        };
    hamcycle(graph1);
    
    int graph2[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                        };
    hamcycle(graph2);
    return 0;
}
