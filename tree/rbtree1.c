#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    int c;
    struct node *p, *r, *l;
};

void swapdata (struct node *u, struct node *v)
{
    int t;
    t = u->d;
    u->d = v->d;
    v->d = t;
}
void swapcolor (struct node *x1, struct node *x2)
{
    int t;
    t = x1->c;
    x1->c = x2->c;
    x2->c =t;
}
    
struct node* newnode (int d)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->d = d;
    t->c = 1;
    t->p = t->r = t->l = NULL;
}
void rightrotate(struct node **root, struct node *p)
{
    struct node* x = p->l;
    
    if (p->l = x->r)
        p->l->p = p;
    
    if (!(x->p = p->p))
        *root = x;
    else if (p == p->p->l)
        p->p->l = x;
    else
        p->p->r = x;
    
    p->p = x;
    x->r = p;
}
void leftrotate (struct node **root, struct node *p)
{
    struct node* x = p->r;
    
    if (p->r = x->l)
        p->r->p = p;
        
    if (!(x->p = p->p))
        *root = x;
    else if (p == p->p->l)
        p->p->l = x;
    else
        p->p->r = x;
        
    x->l = p;
    p->p = x;
}

struct node* uncle (struct node* x)
{
    if (!x->p || !x->p->p)
        return NULL;
    struct node* g = x->p->p;
    
    return (x->p == g->l) ? g->r : g->l;
}
struct node* sibling (struct node* p)
{
    if (p->p == NULL)
        return NULL;
    struct node* g = p->p;
    
    return (p == g->l) ? g->r : g->l;
}
int hasredchild (struct node *p)
{
    if ((p->l && p->l->c) || (p->r && p->r->c))
        return 1;
    
    return 0;
}
struct node* searchnode (struct node* root, int d)
{
    if (root == NULL || root->d == d)
        return root;
    if (d < root->d)
        return searchnode(root->l, d);
        
    return searchnode(root->r, d);
}
struct node* successor (struct node* x)
{
    struct node* t = x;
    
    while (t && t->l)
        t = t->l;
    
    return t;
}
struct node* replace (struct node *x)
{
    if (x->l && x->r)
        return successor(x->r);
    if (x->l)
        return x->l;
    
    return x->r;
}
void fixdoubleblack (struct node **root,struct node* x)
{
    if (x == *root)
        return;
        
    struct node *s = sibling(x);
    struct node *p = x->p;
    
    if (s == NULL)
        fixdoubleblack(root, p);
    else
    {
        if (s->c)
        {
            p->c = 1;
            s->c = 0;
            if (s == p->l)
                rightrotate(root, p);
            else
                leftrotate(root, p);
            
            fixdoubleblack(root, x);
        } else
        {
            if (hasredchild(s))
            {
                if (s->l && s->l->c)
                {
                    if (s == p->l)
                    {
                        s->l->c = s->c;
                        s->c = p->c;
                        rightrotate(root, p);
                    } else
                    {
                        s->l->c = p->c;
                        rightrotate(root, s);
                        leftrotate(root, p);
                    }
                } else
                {
                    if (s == p->l)
                    {
                        s->r->c = p->c;
                        leftrotate(root, s);
                        rightrotate(root, p);
                    } else
                    {
                        s->r->c = s->c;
                        s->c = p->c;
                        leftrotate(root, p);
                    }
                }
                p->c = 0;
            } else
            {
                s->c = 1;
                if (!p->c)
                    fixdoubleblack(root, p);
                else
                    p->c = 0;
            }
        }
    }
}
void deletenode (struct node **root, struct node *v)
{
    struct node* u = replace(v);
    int uvblack = (!u || !u->c) && !v->c;
    struct node* p = v->p;
    
    if (u == NULL)
    {
        if (v == *root)
            *root = NULL;
        else
        {
            if (uvblack)
                fixdoubleblack(root, v);
            
            if (v == p->l)
                p->l = NULL;
            else
                p->r = NULL;
        }
        free (v);
        return;
    }
    if (!v->l || !v->r)
    {
        if (v == *root)
        {
            v->d = u->d;
            v->l = v->r = NULL;
            free (u);
        }
        else
        {
            if (v == p->l)
                p->l = u;
            else
                p->r = u;
                
            free (v);
            u->p = p;
            
            if (uvblack)
                fixdoubleblack(root, u);
            else
                u->c = 0;
        }
        return;
    }
    
    swapdata(u, v);
    deletenode(root, u);
}

int main()
{
    printf("Hello World");

    return 0;
}
