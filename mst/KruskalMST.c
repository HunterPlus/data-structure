#include <stdio.h>
#include <stdlib.h>

struct Edge {int src; int dest; int w;};

struct Graph {int V, E; struct Edge *edge;};

int find (int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
        
    return parent[i];
}

void Union (int parent[], int x, int y)
{
    parent[x] = y;
}

int myCmp (const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge*)a;
    struct Edge *b1 = (struct Edge*)b;
    
    return a1->w > b1->w;
}

struct Graph* createGraph (int V, int E)
{
    struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
    g->V = V;
    g->E = E;
    g->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    
    return g;
}

void KruskalMST (struct Graph *g)
{
    int V = g->V;
    int E = g->E;
    struct Edge result[V];
    
    int i = 0;
    int e = 0;
    
    qsort(g->edge, E, sizeof(struct Edge), myCmp);
    
    int parent[V];
    for (int v = 0; v < V; v++)
        parent[v] = v;
    
    while (e < V-1 && i < E)
    {
        struct Edge nextEdge = g->edge[i++];
        
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);
        
        if (x != y)
        {
            result[e++] = nextEdge;
            Union(parent, x, y);
        }
    }
    
    printf("Following are the edges in the constructed MST\n");
    int cost = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d -- %d == %d\n", result[i].src,
            result[i].dest, result[i].w);
        
        cost += result[i].w;
    }
    printf("Minimum Cost Spanning tree : %d",cost);
}

int main()
{
    /* 
            10
        0--------1
        | \      |
       6|  5\    |15
        |     \  |
        2--------3
            4     */    
    int V = 4;
    int E = 5;
    
    struct Graph* graph = createGraph(V, E);
    
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].w = 10;
    
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].w = 6;
 
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].w = 5;
 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].w = 15;
 
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].w = 4;
 
    KruskalMST(graph);    

    return 0;
}
