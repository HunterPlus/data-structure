#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int vtx;
    int cost;
    struct node *next;
};
struct graph
{
    int V;
    struct node **ha;
};
struct hnode
{
    int vtx;
    int key;
};
struct heap
{
    int cap;
    int n;
    int *pos;
    struct hnode** arr;
};

struct hnode* newhnode (int vtx, int key);
struct heap* createheap (int capacity);
void swaphnode (struct hnode **a, struct hnode **b);
int empty (struct heap *hp);
int inheap (struct heap *hp, int vtx);
void heapify (struct heap *hp, int i);
struct hnode* exact (struct heap *hp);
void decrease (struct heap *hp, int vtx, int key);
struct node* newnode (int vtx, int cost);
void push (struct node **h, int vtx, int cost);
struct graph* creategraph (int V);
void addedge (struct graph *g, int src, int dst, int cost);
void primMST (struct graph *g);
void printgraph(struct graph *g);
void printarr(int arr[], int n);
/**************************************************************************/

struct hnode* newhnode (int vtx, int key)
{
    struct hnode *t = (struct hnode*)malloc(sizeof(struct hnode));
    t->vtx = vtx;
    t->key = key;
    return t;
}
struct heap* createheap (int capacity)
{
    struct heap *hp = (struct heap*)malloc(sizeof(struct heap));
    hp->cap = capacity;
    hp->n = 0;
    hp->pos = (int*)malloc(capacity * sizeof(int));
    hp->arr = (struct hnode**)malloc(capacity * sizeof(struct hnode *));
    return hp;
}
void swaphnode (struct hnode **a, struct hnode **b)
{
    struct hnode *t = *a;
    *a = *b;
    *b = t;
}
int empty (struct heap *hp) { return hp->n == 0; }
int inheap (struct heap *hp, int vtx) { return hp->pos[vtx] < hp->n; }

void heapify (struct heap *hp, int i)
{
    int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < hp->n && hp->arr[l]->key < hp->arr[min]->key)
        min = l;
    if (r < hp->n && hp->arr[r]->key < hp->arr[min]->key)
        min = r;
    if (min != i)
    {
        struct hnode *minnode = hp->arr[min];
        struct hnode *inode = hp->arr[i];
        
        hp->pos[minnode->vtx] = i;
        hp->pos[inode->vtx] = min;
        swaphnode(&hp->arr[min], &hp->arr[i]);
        
        heapify(hp, min);
    }
}
struct hnode* exact (struct heap *hp)
{
    if (empty(hp))
        return NULL;
        
    struct hnode *root = hp->arr[0];
    struct hnode *last = hp->arr[--hp->n];
    hp->arr[0] = last;
    
    hp->pos[root->vtx] = hp->n;
    hp->pos[last->vtx] = 0;
    
    heapify(hp, 0);
    return root;
}
void decrease (struct heap *hp, int vtx, int key)
{
    int i = hp->pos[vtx];
    hp->arr[i]->key = key;
    
    while (i && hp->arr[i]->key < hp->arr[(i-1)/2]->key)
    {
        hp->pos[vtx] = (i-1) / 2;
        struct hnode *p = hp->arr[(i-1)/2];
        hp ->pos[p->vtx] = i;
        
        swaphnode(&hp->arr[i], &hp->arr[(i-1)/2]);
        
        i = (i-1) / 2;
    }
}

struct node* newnode (int vtx, int cost)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->vtx = vtx;
    t->cost = cost;
    t->next = NULL;
    
    return t;
}
void push (struct node **h, int vtx, int cost)
{
    struct node *t = newnode(vtx, cost);
    t->next = *h;
    *h = t;
}
struct graph* creategraph (int V)
{
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    g->V = V;
    g->ha = (struct node**)malloc(V * sizeof(struct node*));
    
    for (int i = 0; i < V; i++)
        g->ha[i] = NULL;
    return g;
}
void addedge (struct graph *g, int src, int dst, int cost)
{
    push(&g->ha[src], dst, cost);
    push(&g->ha[dst], src, cost);
}
void printgraph(struct graph *g)
{
    for (int v = 0; v < g->V; v++)
    {
        struct node *h = g->ha[v];
        printf("\nAdjacency list of vertex %d\n head", v);
        while (h)
        {
            printf("-> %d[%d]", h->vtx, h->cost);
            h = h->next;
        }
        printf("\n");
    }
}

void primMST (struct graph *g)
{
    int V = g->V;
    int path[V];
    int cost[V];
    
    struct heap *hp = createheap(V);
    
    for (int i = 1; i < V; i++)
    {
        path[i] = -1;
        cost[i] = INT_MAX;
        
        hp->arr[i] = newhnode(i, INT_MAX);
        hp->pos[i] = i;
    }
    
    cost[0] = 0;
    hp->arr[0] = newhnode(0, 0);
    hp->pos[0] = 0;
    hp->n = V;
    
    while (!empty(hp))
    {
        struct hnode *minhnode = exact(hp);
        int u = minhnode->vtx;
        
        struct node *q = g->ha[u];
        while(q)
        {
            int v = q->vtx;
            if (inheap(hp, v) && q->cost < cost[v])
            {
                cost[v] = q->cost;
                path[v] = u;
                decrease(hp, v, cost[v]);
            }
            q = q->next;
        }
    }
    printarr(path, V);
}
void printarr(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}


int main()
{
    int V = 9;
    struct graph* g = creategraph(V);
    addedge(g, 0, 1, 4);
    addedge(g, 0, 7, 8);
    addedge(g, 1, 2, 8);
    addedge(g, 1, 7, 11);
    addedge(g, 2, 3, 7);
    addedge(g, 2, 8, 2);
    addedge(g, 2, 5, 4);
    addedge(g, 3, 4, 9);
    addedge(g, 3, 5, 14);
    addedge(g, 4, 5, 10);
    addedge(g, 5, 6, 2);
    addedge(g, 6, 7, 1);
    addedge(g, 6, 8, 6);
    addedge(g, 7, 8, 7);
    
    primMST(g);

    return 0;
}
