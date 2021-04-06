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
struct node* bstinsert (struct node *t, struct node *x)
{
    if (t == NULL)
        return x;
    if (x->d < t->d)
    {
        t->l = bstinsert(t->l, x);
        t->l->p = t;
    }
    else if (x->d > t->d)
    {
        t->r = bstinsert(t->r, x);
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

void fixup (struct node *root, struct node *x)
{
    struct node *p = NULL;
    struct node *g = NULL;
    
    while ((x != root) && x->c && x->p->c)
    {
        p = x->p;
        g = x->p->p;
        
        if (p == g->l)
        {
            struct node *u = g->r;
            
            if (u && u->c)
            {
                g->c = 1;
                p->c = 0;
                u->c = 0;
                
                x = g;
            } else
            {
                if (x == p->r)
                {
                    leftrotate(&root, p);
                    x = p;
                    p = x->p;
                }
                rightrotate(&root, g);
                int t = p->c;
                p->c = g->c;
                g->c = t;
                
                x = p;
            }
        } else
        {
            struct node *u = g->l;
            
            if (u && u->c)
            {
                g->c = 1;
                p->c = 0;
                u->c = 0;
                
                x = g;
            } else
            {
                if (x == p->l)
                {
                    rightrotate(&root, p);
                    x = p;
                    p = x->p;
                }
                leftrotate(&root, g);
                int t = p->c;
                p->c = g->c;
                g->c = t;
                
                x = p;
            }
        } 
    }
    
    root->c = 0;
}
