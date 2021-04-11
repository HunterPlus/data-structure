#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    int c;
    struct node *p, *r, *l;
};

struct node* newnode (int d)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->d = d;
    t->c = 1;
    t->p = t->r = t->l = NULL;
}

struct node* search(struct node* root, int d)
{
    struct node* t = root;
    while (t)
    {
        if (d == t->d)
            return t;
        else if (d < t->d)
            t = t->l;
        else
            t = t->r;
    }
    return NULL;
}


struct node *bstinsert(struct node *t, struct node *x)
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
void fixred(struct node **root, struct node *x)
{
    struct node *p = NULL;
    struct node *g = NULL;

    while ((x != *root) && x->c && x->p->c)
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
            }
            else
            {
                if (x == p->r)
                {
                    leftrotate(root, p);
                    x = p;
                    p = x->p;
                }
                rightrotate(root, g);
                int t = p->c;
                p->c = g->c;
                g->c = t;

                x = p;
            }
        }
        else
        {
            struct node *u = g->l;

            if (u && u->c)
            {
                g->c = 1;
                p->c = 0;
                u->c = 0;

                x = g;
            }
            else
            {
                if (x == p->l)
                {
                    rightrotate(root, p);
                    x = p;
                    p = x->p;
                }
                leftrotate(root, g);
                int t = p->c;
                p->c = g->c;
                g->c = t;

                x = p;
            }
        }
    }

    (*root)->c = 0;
}
void rbinsert (struct node **root, int d)
{
    struct node* t = newnode(d);
    *root = bstinsert(*root, t);
    fixred(root, t);
}

struct node* successor (struct node* x)
{
    struct node* t = x;
    
    while (t && t->l)
        t = t->l;
    
    return t;
}
void fixblack (struct node **root, struct node *x)
{
    if (x == *root)
        return ;
    
    struct node *p = x->p;
    struct node *s = (x == p->l) ? p->r : p->l;
    int hasred = (s->l && s->l->c) || (s->r && s->r->c);
    
    if (s->c == 1)
    {
        p->c = 1;
        s->c = 0;
        
        (s == p->l)? rightrotate(root, p) : leftrotate(root, p);
        
        fixblack(root, x);
    } else 
    {
        if (hasred)
        {
            if (s == p->l) {
                if (s->l)
                {
                    s->l->c = s->c;
                    s->c = p->c;
                    rightrotate(root, p);
                } else 
                {
                    s->r->c = p->c;
                    leftrotate(root, s);
                    rightrotate(root, p);
                }
            } else
            {
                if (s->r)
                {
                    s->r->c = s->c;
                    s->c = p->c;
                    leftrotate(root, p);
                } else
                {
                    s->l->c = p->c;
                    rightrotate(root, s);
                    leftrotate(root, p);
                }
            }
            
        } else
        {
            s->c = 1;
            if (p->c == 0)
                fixblack(root, p);
            p->c = 0;
        }
    }
}

void deletenode (struct node **root, struct node *v)
{
    if (v->l && v->r)
    {
        struct node *u = successor(v->r);
        int tmp = v->d;
        v->d = u->d;
        u->d = tmp;
        
        return deletenode(root, u);
    }
    struct node *p = v->p;
    struct node *u = v->l ? v->l : v->r;
    if (u == NULL)
    {
        if (v == *root)
            *root = NULL;
        else {
            if (v->c == 0)
                fixblack(root, v);
            
            if (v == p->l)
                p->l = NULL;
            else
                p->r = NULL;
        }
        free(v);
        
        return;
    }
    if (v == *root)
    {
        v->d = u->d;
        v->l = v->r = NULL;
        
        free(u);
        
        return;
    }
    if (v == p->l)
        p->l = u;
    else
        p->r = u;
    u->p = p;
    u->c = 0;
    free(v);
    
    return;
}
void rbdelete (struct node **root, int d)
{
    struct node *x = search(*root, d);
    if (x == NULL)
        return ;
    
    deletenode(root, x);
}
void inorder(struct node *t)
{
    if (t == NULL)
        return;
    inorder(t->l);
    printf("%d ", t->d);
    inorder(t->r);
}

/******************************************************************/
struct Queue { int cap, n, f, r; void **a; };
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
void levelorder (struct node *root)
{
    struct Queue *q = createQ(100);
    struct node* t = root;
    
    while (t)
    {
        printf ("%d ", t->d);
        
        if (t->l)
            enQ(q, t->l);
        if (t->r)
            enQ(q, t->r);
        t = deQ(q);
    }
}
/*******************************************************************/

int main()
{
    int a[] = {7, 3, 18, 10, 22, 8, 11, 26, 2, 6, 13};
    int n = sizeof(a) / sizeof(a[0]);
    
    struct node *t, *root = NULL;

    for (int i = 0; i < n; i++)
    {
        //t = newnode(a[i]);
        //root = bstinsert(root, t);
        //fixup(&root, t);
        
        rbinsert(&root, a[i]);        
    }

    printf("Inoder Traversal of Created Tree\n");
    inorder(root);
    printf("\n");
    levelorder(root);
    
    t = search(root, 10);
    printf("\nkey found: %d", t->d);

    return 0;
}


