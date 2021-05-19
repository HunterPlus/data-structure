#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vtx;
    struct node *next;
};

struct graph
{
    int V;
    struct node **ha;
};

void toposort (struct graph *g);
/***********************************************************************/
struct node *newnode (int vtx);
void push (struct node **h, int vtx);
struct graph *creategraph (int V);
void addedge (struct graph *g, int src, int dst);
void printgraph(struct graph *g);
/***********************************************************************/

void toposort (struct graph *g)
{
    int V = g->V;
    
    int indeg[V];
    for (int i = 0; i < V; i++)
        indeg[i] = 0;
    
    int f, r;        // front, rear
    int queue[V];
    f = r = -1;
    
    for (int u = 0; u < V; u++)
    {
        struct node *h = g->ha[u];
        
        while (h)
        {
            int v = h->vtx;
            indeg[v]++;
            
            h = h->next;
        }
    }
    
    for (int u = 0; u < V; u++)
        if (indeg[u] == 0)
            queue[++r] = u;
            
    int count = 0;
    while (f != r)
    {
        int u = queue[++f];
        struct node *h = g->ha[u];
        while (h)
        {
            int v = h->vtx;
            if (--indeg[v] == 0)
                queue[++r] = v;
                
            h = h->next;
        }
        
        count++;
    }
    
    if (count != V) {
        printf("There exists a cycle in the graph\n");
        return;
    }
    for (int i = 0; i < V; i++)
        printf("%d ", queue[i]);
}

struct node *newnode (int vtx)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->vtx = vtx;
    t->next = NULL;
    
    return t;
}
void push (struct node **h, int vtx)
{
    struct node *t = newnode(vtx);
    
    t->next = *h;
    *h = t;
}
struct graph *creategraph (int V)
{
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    
    g->V = V;
    g->ha = (struct node**)malloc(V * sizeof(struct node*));
    for (int i = 0; i < V; i++)
        g->ha[i] = NULL;
    
    return g;
}
void addedge (struct graph *g, int src, int dst)
{
    push(&g->ha[src], dst);
    
    return ;
}
void printgraph(struct graph *g)
{
    for (int v = 0; v < g->V; v++)
    {
        struct node *h = g->ha[v];
        printf("\nAdjacency list of vertex %d\n head", v);
        while (h)
        {
            printf("-> %d", h->vtx);
            h = h->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 6;
    struct graph *g = creategraph(V);

    addedge(g, 5, 2);
    addedge(g, 5, 0);
    addedge(g, 4, 0);
    addedge(g, 4, 1);
    addedge(g, 2, 3);
    addedge(g, 3, 1);    
    
    printgraph(g);
    
    toposort(g);

    return 0;
}
