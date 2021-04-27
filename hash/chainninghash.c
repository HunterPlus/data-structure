#include <stdio.h>
#include <stdlib.h>

#define HSIZE 7

struct node
{
    int key;
    struct node *next;
};
struct node *newnode (int key)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->key = key;
    t->next = NULL;
    return t;
}
void push (struct node **h, int key)
{
    struct node *t = newnode(key);
    
    t->next = *h;
    *h = t;
    return;
}
struct node **createhash ()
{
    struct node **ht = (struct node**)malloc(HSIZE * sizeof(struct node*));
    for (int i = 0; i < HSIZE; i++)
        ht[i] = NULL;
    return ht;
}
int hash (int x) { return x % HSIZE; }

void insert (struct node **ht, int key)
{
    int idx = hash(key);
    push(ht+idx, key);
}
void delete (struct node **ht, int key)
{
    int idx = hash(key);
    struct node *p = ht[idx];
    struct node *q = NULL; 
    
    if (p && p->key == key)
    {
        ht[idx] = p->next;
        free(0);
        return ;
    }
    while (p && p->key != key)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return ;
        
    q->next = p->next;
    free(p);

}
void printhash (struct node **ht)
{
    for (int i = 0; i < HSIZE; i++)
    {
        printf("%d-->", i);
        struct node *p = ht[i];
        while (p)
        {
            printf("%2d ", p->key);
            p = p->next;
        }
        printf("\n");
    }
}


int main()
{
    int a[] = {15, 11, 27, 8, 12, 26, 38, 24, 9, 5, 32, 14};
    int n = sizeof(a)/sizeof(a[0]);
    
    struct node **ht = createhash();
    for (int i = 0; i < n; i++)
        insert(ht, a[i]);
    
    printhash(ht);
    
    delete(ht, 12);
    printhash(ht);

    return 0;
}
