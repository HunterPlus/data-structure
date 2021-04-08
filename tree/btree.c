#include <stdio.h>
#include <stdlib.h>

#define MIN     3
#define MAX     2 * MIN

struct node
{
    int n;
    int leaf;
    int *ks;
    struct node** cs;
};

struct node* newnode (int leaf)
{
    struct node* b = (struct node*)malloc(sizeof(struct node));
    
    b->n = 0;
    b->leaf = leaf;
    b->ks = (int*)malloc((MAX-1) * sizeof(int));
    b->cs = (struct node**)malloc(MAX * sizeof(struct node*));
    
    return b;
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
void splitchild (struct node *x, struct node *y, int i)
{
    struct node *z = newnode(y->leaf);
    z->n = MIN - 1;
    
    for (int j = 0; j < MIN-1; j++)
        z->ks[j] = y->ks[MIN + j];
        
    if (y->leaf == 0)
        for (int j = 0; j < MIN; j++)
            z->cs[j] = y->cs[MIN + j];
    
    y->n = MIN - 1;
    
    for (int j = x->n; j >= i+1; j--)
        x->cs[j + 1] = x->cs[j];
        
    x->cs[i + 1] = z;
    
    for (int j = x->n - 1; j >= i; j--)
        x->ks[j + 1] = x->ks[j];
        
    x->ks[i] = y->ks[MIN - 1];
    x->n++;
}
void insertnonfull (struct node *x, int k)
{
    int i = x->n - 1;
    
    if (x->leaf == 1)
    {
        for (; i >= 0 && x->ks[i] > k; i--)
            x->ks[i + 1] = x->ks[i];
            
        x->ks[i + 1] = k;
        x->n++;
    }
    else
    {
        for (; i >= 0 && x->ks[i] > k; i--) ;
        
        struct node* y = x->cs[i + 1];
        if (y->n == MAX - 1)
        {
            splitchild(x, y, i+1);
            
            if (x->ks[i + 1] < k)
                y = x->cs[++i + 1];
        }
        
        insertnonfull(y, k);
    }
}
void insert (struct node **root, int k)
{
    if (*root == NULL)
    {
        *root = newnode(1);
        (*root)->ks[0] = k;
        (*root)->n++;
    }
    else
    {
        if ((*root)->n == MAX - 1)
        {
            struct node* s = newnode(0);
            
            s->cs[0] = *root;
            splitchild(s, *root, 0);
            
            int i = 0;
            if (s->ks[0] < k)
                i++;
            insertnonfull(s->cs[i], k);
            
            *root = s;
        }
        else
            insertnonfull(*root, k);
    }
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
