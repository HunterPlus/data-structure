#include <stdio.h>
#include <stdlib.h>
#define t 3
struct node
{
    int n;
    int leaf;
    int *ks;
    struct node **cs;
};

struct node *newnode (int leaf)
{
    struct node *b = (struct node*)malloc(sizeof(struct node));
    b->n = 0;
    b->leaf = leaf;
    
    b->ks = (int *)malloc((2*t - 1) * sizeof(int));
    b->cs = (struct node**)malloc(2*t * sizeof(struct node*));
    
    return b;
}

void split (struct node *x, struct node *y, int i)
{
    struct node *z = newnode(y->leaf);
    z->n = t - 1;
    
    if (y->leaf == 0)
        for (int j = 0; j < t; j++)
            z->cs[j] = y->cs[t + j];
    for (int j = 0; j < t-1; j++)
        z->ks[j] = y->ks[t + j];
    
    y->n = t - 1; 
    
    for (int j = x->n; j >= i+1; j--)
        x->cs[j + 1] = x->cs[j];
    x->cs[i + 1] = z;
    for (int j = x->n-1; j >= i; j--)
        x->ks[j + 1] = x->ks[j];
    x->ks[i] = y->ks[t-1];
    
    x->n += 1;
}
void fill (struct node *x, int k)
{
    int i;
    
    if (x->leaf == 1)
    {
        for (i = x->n - 1; i >= 0 && k < x->ks[i]; i--)
            x->ks[i + 1] = x->ks[i];
        x->ks[i + 1] = k;
        x->n += 1;
    } 
    else
    {
        for (i = 0; i < x->n && k > x->ks[i]; i++)
            /*nothing*/;
            
        if (x->cs[i]->n == 2*t -1)
        {
            split(x, x->cs[i], i);
            
            if (k > x->ks[i])
                i++;
        }
        
        fill (x->cs[i], k);
    }
}

void insert (struct node **root, int k)
{
    if (*root == NULL)
    {
        *root = newnode(1);
        
        (*root)->ks[0] = k;
        (*root)->n = 1;
    } 
    else
    {
        if ((*root)->n == 2*t - 1)
        {
            struct node *s = newnode(0);
            s->cs[0] = *root;
            
            split(s, *root, 0);
            
            int i = 0;
            if (k > s->ks[i])
                i++;
            fill(s->cs[i], k);
            *root = s;
        }
        else
            fill(*root, k);
    }
}

void traverse (struct node *b)
{
    int i;
    for (i = 0; i < b->n; i++)
    {
        if (b->leaf == 0)
            traverse(b->cs[i]);
            
        printf("%d ", b->ks[i]);
    }
    if (b->leaf == 0)
        traverse(b->cs[i]);
}
struct node* search (struct node *b, int k)
{
    int i = 0;
    while (i < b->n && k > b->ks[i])
        i++;
        
    if (k == b->ks[i])
        return b;
    if (b->leaf == 1)
        return NULL;
    return search(b->cs[i], k);
}

int main()
{
    struct node* root = NULL;
    
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 7);
    insert(&root, 17);
    
    traverse(root);

    int k = 6;
    (search(root, k)!=NULL) ? printf("\npresent\n") : printf("\nnot present\n");
    
    k = 15;
    (search(root, k)!=NULL) ? printf("present") : printf("not present");

    return 0;
}
