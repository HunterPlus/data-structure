#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int src;
    int dst;
};
struct graph
{
    int V, E;
    struct edge *eg;
};
struct graph *creategraph (int V, int E)
{
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    g->V = V;
    g->E = E;
    g->eg = (struct edge*)malloc(E * sizeof(struct edge));
    
    return g;
}
int find (int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
int Union (int parent[], int x, int y)
{
    parent[x] = y;
}
int cycle (struct graph *g)
{
    int *parent = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++)
        parent[i] = -1;
    
    for (int i = 0; i < g->E; i++)
    {
        int x = find(parent, g->eg[i].src);
        int y = find(parent, g->eg[i].dst);
        
        if (x == y)
            return 1;
        Union(parent, x, y);
    }
    return 0;
}

int main()
{
   int V = 3, E = 3;
    struct graph* g = creategraph(V, E);
    
    g->eg[0].src = 0;
    g->eg[0].dst = 1;
    g->eg[1].src = 1;
    g->eg[1].dst = 2;
    g->eg[2].src = 0;
    g->eg[2].dst = 2;
    
    if (cycle(g))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
    return 0;
}
