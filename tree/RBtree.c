#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    int c;
    struct node *p, *r, *l;
};

struct node *newnode (int d)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    
    t->d = d;
    t->c = 1;
    t->p = t->r = t->l = NULL;
    
    return t;
}
struct node* bst (struct node *t, int d)
{
    if (t == NULL)
        return newnode(d);
    if (d < t->d)
    {
        t->l = bst(t->l, d);
        t->l->p = t;
    }
    else if (d > t->d)
    {
        t->r = bst(t->r, d);
        t->r->p = t;
    }
    
    return t;
}

void rightrotate (struct node **root, struct node *p)
{
    struct node *x = p->l;
    
    if (p->l = x->r)
        p->l->p = p;
    
    if (!(x->p = p->p))
        *root = x;
    else if (p == p->p->l)
        p->p->l = x;
    else
        p->p->r = x;
        
    x->r = p;
    p->p = x;
}

void leftrotate (struct node **root, struct node *p)
{
    struct node *x = p->r;
    
    if (p->r = x->l)
        p->r->p = p;
    
    if (!(x->p = p->p))
        *root = x;
    else if (p == p->p->l)
        p->p->l = x;
    else
        p->p->r =x;
        
    x->l = p;
    p->p = x;
}
