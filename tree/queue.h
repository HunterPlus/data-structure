#include <stdlib.h>

struct Queue { 
    int cap;
    int n;
    int f;
    int r; 
    
    void **a; 
};

struct Queue *createQ (int cap)
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->cap = cap;
    q->n = 0;
    q->f = 0;
    q->r = cap - 1;
    q->a = (void**)malloc(cap * sizeof(void*));
    
    return q;
}
int isEmpty (struct Queue *q) {return (q->n == 0); }
int isFull (struct Queue *q) {return (q->n == q->cap); }
void enQ (struct Queue *q, void *p)
{
    if (isFull(q)) return;
    
    q->r = (q->r+1) % q->cap;
    q->a[q->r] = p;
    q->n++;
}
void *deQ (struct Queue *q)
{
    if (isEmpty(q)) return NULL;
    
    void *p = q->a[q->f];
    q->f = (q->f+1) % q->cap;
    q->n--;
    
    return p;
}
