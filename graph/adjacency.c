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

struct graph* creategraph (int V);
void addedge (struct graph *g, int src, int dst);
void printgraph(struct graph *g);
struct node* newnode (int vtx);
void push (struct node **h, int vtx);
/******************************************************************/
struct graph* creategraph (int V)
{
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    g->V = V;
    
    g->ha = (struct node**)malloc(V * sizeof(struct node *));
    for (int i = 0; i < V; i++)
        g->ha[i] = NULL;
    
    return g;
}
void addedge (struct graph *g, int src, int dst)
{
    push(&g->ha[src], dst);
    
    push(&g->ha[dst], src);
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

struct node* newnode (int vtx)
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

int main()
{
    int V = 5;
    struct graph *g = creategraph(5);

    addedge(g, 0, 1);
    addedge(g, 0, 4);
    addedge(g, 1, 2);
    addedge(g, 1, 3);
    addedge(g, 1, 4);
    addedge(g, 2, 3);
    addedge(g, 3, 4);    
    
    printgraph(g);

    return 0;
}
