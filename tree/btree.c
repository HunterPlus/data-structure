#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define t 3

struct node
{
    int n;
    int leaf;
    int *ks;
    struct node **cs;
};
struct node *newnode (int leaf);

void traverse (struct node *x);
struct node *search (struct node *x, int k);
void insert (struct node **root, int k);
void insertnonfull (struct node *x, int k);
void splitchild (struct node *x, int i);

void delete (struct node **root, int k);
int findkey (struct node *x, int k);
void rm (struct node *x, int k);
void rmfromleaf (struct node *x, int idx);
void rmfromnonleaf (struct node *x, int idx);
int getpred (struct node *x, int idx);
int getsucc (struct node *x, int idx);
void merge (struct node *x, int idx);
void fill (struct node *x, int idx);
void borrowleft (struct node *x, int idx);
void borrowright (struct node *x, int idx);
/*************************************************************************/
struct node *newnode (int leaf)
{
    struct node *x = (struct node*)malloc(sizeof(struct node));
    x->n = 0;
    x->leaf = leaf;
    x->ks = (int *)malloc((2*t-1) * sizeof(int));
    x->cs = (struct node**)malloc(2*t * sizeof(struct node **));
}
void leveltrav (struct node *x)
{
    struct Queue *q = createQ(50);
    
    enQ(q, x);
    
    while (!isEmpty(q))
    {
        struct node *y = deQ(q);
        for (int i = 0; i < y->n; i++)
            printf("%d ", y->ks[i]);
        printf("\n");
        
        if (y->leaf == 0)
            for (int i = 0; i <= y->n; i++)
                enQ(q, y->cs[i]);
    }
}
void traverse (struct node *x)
{
    int i;
    for (i = 0; i < x->n; i++)
    {
        if (!x->leaf)
            traverse(x->cs[i]);
        
        printf("%d ", x->ks[i]);
    }
    if (!x->leaf)
        traverse(x->cs[i]);
}
struct node *search (struct node *x, int k)
{
    int i;
    for (i = 0; i < x->n && x->ks[i] < k; i++)
        /*nothing*/;
    if (x->ks[i] == k)
        return x;
    if (x->leaf)
        return NULL;
    return search(x->cs[i], k);
}
void insert (struct node **root, int k)
{   
    if (*root == NULL)
    {
        struct node *x = newnode(1);
        x->ks[0] = k;
        x->n = 1;
        
        *root = x;
        return ;
    } 
    if ((*root)->n == 2*t - 1)
    {
        struct node *s = newnode(0);
        s->cs[0] = *root;
        splitchild(s, 0);
        
        int i = 0;
        if (k > s->ks[0])
            i++;
        insertnonfull(s->cs[i], k);
        
        *root = s;
    } else
        insertnonfull(*root, k);
}
void insertnonfull (struct node *x, int k)
{
    int i;
    if (x->leaf)
    {
        for (i = x->n - 1; i >= 0 && x->ks[i] > k; i--)
            x->ks[i + 1] = x->ks[i];
        x->ks[i + 1] = k;
        x->n += 1;
    } else
    {
        for (i = 0; i < x->n && x->ks[i] < k; i++)
            /*nothing*/;
        if (x->cs[i]->n == 2*t -1)
        {
            splitchild(x, i);
            if (x->ks[i] < k)
                i++;
        }
        insertnonfull(x->cs[i], k);
    }
}
void splitchild (struct node *x, int i)
{
    struct node *y = x->cs[i];
    struct node *z = newnode(y->leaf);
    z->n = t - 1;
    
    for (int j = x->n - 1; j >= i; j--)
        x->ks[j + 1] = x->ks[j];
    x->ks[i] = y->ks[t - 1];
    for (int j = x->n; j >= i+1; j--)
        x->cs[j + 1] = x->cs[j];
    x->cs[i + 1] = z;
    
    for (int j = 0; j < t-1; j++)
        z->ks[j] = y->ks[t + j];
    if (y->leaf == 0)
        for (int j = 0; j < t; j++)
            z->cs[j] = y->cs[t + j];
    
    x->n += 1;
    y->n = t - 1;
    
}
void delete (struct node **root, int k)
{
    if (*root == NULL)
    {
        printf("The B tree is empty!\n");
        return ;
    } else
        rm(*root, k);
    
    if ((*root)->n == 0)
    {
        struct node *tmp = *root;
        
        if ((*root)->leaf)
            *root = NULL;
        else
            *root = (*root)->cs[0];
        
        free(tmp);
    }
    return ;
}
int findkey (struct node *x, int k)
{
    int idx = 0;
    while (idx < x->n && x->ks[idx] < k)
        idx++;
    return idx;
}
void rm (struct node *x, int k)
{
    int idx = findkey(x, k);
    
    if (idx < x->n && x->ks[idx] == k)
    {
        if (x->leaf == 1)
            rmfromleaf(x, idx);
        else
            rmfromnonleaf(x, idx);
    } else
    {
        if (x->leaf == 1)
        {
            printf("The key %d is no present!!!\n", k);
            return;
        } else
        {
            int flag = (idx == x->n) ? 1 : 0;
            
            if (x->cs[idx]->n < t)
                fill(x, idx);
            if (flag && idx > x->n)
                rm(x->cs[idx - 1], k);
            else
                rm(x->cs[idx], k);
        }
    }
}
void rmfromleaf (struct node *x, int idx)
{
    for (int i = idx+1; i < x->n; i++)
        x->ks[i -1] = x->ks[i];
    x->n -= 1;
    return ;
}
void rmfromnonleaf (struct node *x, int idx)
{
    int k = x->ks[idx];
    
    if (x->cs[idx]->n >= t)
    {
        int pred = getpred(x, idx);
        x->ks[idx] = pred;
        rm(x->cs[idx], pred);
    } else if (x->cs[idx+1]->n >= t)
    {
        int succ = getsucc(x, idx);
        x->ks[idx] = succ;
        rm(x->cs[idx+1], succ);
    } else
    {
        merge(x, idx);
        rm(x, k);
    }
    return ;
}
int getpred (struct node *x, int idx)
{
    struct node *cur = x->cs[idx];
    
    while (!cur->leaf)
        cur = cur->cs[cur->n];
    return cur->ks[cur->n - 1];
}
int getsucc (struct node *x, int idx)
{
    struct node *cur = x->cs[idx+1];
    while (!cur->leaf)
        cur = cur->cs[0];
    return cur->ks[0];
}
void fill (struct node *x, int idx)
{
    if (idx != 0 && x->cs[idx-1]->n >= t)
        borrowleft(x, idx);
    else if (idx != x->n && x->cs[idx+1]->n >= t)
        borrowright(x, idx);
    else
    {
        if (idx == x->n)
            merge(x, idx-1);
        else
            merge(x, idx);
    }
    return ;
}
void borrowleft (struct node *x, int idx)
{
    struct node *y = x->cs[idx];
    struct node *z = x->cs[idx - 1];
    
    for (int i = y->n; i > 0; i--)
        y->ks[i] = y->ks[i - 1];
    y->ks[0] = x->ks[idx - 1];
    x->ks[idx - 1] = z->ks[z->n - 1];
    
    if (!y->leaf)
    {
        for (int i = y->n; i >= 0; i--)
            y->cs[i+1] = y->cs[i];
        y->cs[0] = z->cs[z->n];
    }
    y->n += 1;
    z->n -= 1;
    
    return ;
}
void borrowright (struct node *x, int idx)
{
    struct node *y = x->cs[idx];
    struct node *z = x->cs[idx+1];
    
    y->ks[y->n] = x->ks[idx];
    x->ks[idx] = z->ks[0];
    for (int i = 0; i < z->n-1; i++)
        z->ks[i] = z->ks[i + 1];
        
    if (!y->leaf)
    {
        y->cs[y->n + 1] = z->cs[0];
        for (int i = 0; i < z->n; i++)
            z->cs[i] = z->cs[i + 1];
    }
    y->n += 1;
    z->n -= 1;
    
    return ;
}
void merge (struct node *x, int idx)
{
    struct node *y = x->cs[idx];
    struct node *z = x->cs[idx + 1];
    
    y->ks[t - 1] = x->ks[idx];
    
    for (int j = 0; j < z->n; j++)
        y->ks[t + j] = z->ks[j];
    if (!y->leaf)
        for (int j = 0; j <= z->n; j++)
            y->cs[t + j] = z->cs[j];
            
    for (int j = idx; j < x->n-1; j++)
        x->ks[j] = x->ks[j + 1];
    for (int j = idx+1; j < x->n; j++)
        x->cs[j] = x->cs[j + 1];
        
    x->n -= 1;
    y->n += z->n + 1;
    
    free (z);
    return ;
}

int main()
{
    struct node* root = NULL;
    
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 10);
    insert(&root, 11);
    
    insert(&root, 13);
    insert(&root, 14);
    insert(&root, 15);
    insert(&root, 18);
    
    insert(&root, 16);
    insert(&root, 19);
    insert(&root, 24);
    insert(&root, 25);
    
    insert(&root, 26);
    insert(&root, 21);
    insert(&root, 4);
    insert(&root, 5);
    
    insert(&root, 20);
    insert(&root, 22);
    insert(&root, 2);
    insert(&root, 17);
    
    insert(&root, 12);
    insert(&root, 6);


    
    traverse(root);
    printf("\n");
    leveltrav(root);
    
    delete (&root, 6);
    delete (&root, 13);
    delete (&root, 7);
    delete (&root, 4);
    delete (&root, 2);
    delete (&root, 16);
    printf("\n");
    leveltrav(root);

    return 0;
}
