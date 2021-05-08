#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 100

struct node
{
    char ch;
    int freq;
    struct node *l, *r;
};
struct heap
{
    int size;
    int cap;
    struct node **arr;
};
struct node *newnode (char ch, int freq)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->ch = ch;
    t->freq = freq;
    t->l = t->r = NULL;
    return t;
}
struct heap *createheap (int capacity)
{
    struct heap *hp = (struct heap*)malloc(sizeof(struct heap));
    hp->size = 0;
    hp->cap = capacity;
    hp->arr = (struct node**)malloc(capacity * sizeof(struct node*));
    
    return hp;
}
void swapnode (struct node **a, struct node **b)
{
    struct node *t = *a;
    *a = *b;
    *b = t;
}
void heapify (struct heap *hp, int i)
{
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < hp->size && hp->arr[left]->freq < hp->arr[min]->freq)
        min = left;
    if (right < hp->size && hp->arr[right]->freq < hp->arr[min]->freq)
        min = right;
    if (min != i)
    {
        swapnode(&hp->arr[i], &hp->arr[min]);
        heapify(hp, min);
    }
}
struct node *exactheap (struct heap *hp)
{
    if (hp->size == 0)
        return NULL;
        
    struct node *t = hp->arr[0];
    hp->arr[0] = hp->arr[hp->size - 1];
    
    hp->size--;
    heapify(hp, 0);
    
    return t;
}
void insertheap (struct heap *hp, struct node *nd)
{
    hp->size++;
    int i = hp->size - 1;
    while (i > 0 && nd->freq < hp->arr[(i-1) / 2]->freq)
    {
        hp->arr[i] = hp->arr[(i-1) / 2];
        i = (i-1) / 2;
    }
    hp->arr[i] = nd;
}
void buildheap (struct heap *hp)
{
    int j = hp->size - 1;
    int i;
    
    for (i = (j-1) / 2; i >= 0; i--)
        heapify(hp, i);
}
void printarray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
struct heap *createandbuildheap (char data[], int freq[], int n)
{
    struct heap *hp = createheap(n);
    
    for (int i = 0; i < n; i++)
        hp->arr[i] = newnode(data[i], freq[i]);
   
    hp->size = n;
    buildheap(hp);
    return hp;
}
struct node *huffmantree (char data[], int freq[], int n)
{
    struct node *left, *right, *top;
    struct heap *hp = createandbuildheap(data, freq, n);
    
    while (hp->size > 1)
    {
        left = exactheap(hp);
        right = exactheap(hp);
        
        top = newnode('$', left->freq + right->freq);
        
        top->l = left;
        top->r = right;
        
        insertheap(hp, top);
    }
    return exactheap(hp);
}
void printcodes (struct node *root, int arr[], int top)
{
    if (root->l)
    {
        arr[top] = 0;
        printcodes(root->l, arr, top+1);
    }
    if (root->r)
    {
        arr[top] = 1;
        printcodes(root->r, arr, top+1);
    }
    if (!root->l && !root->r)
    {
        printf("%c: ", root->ch);
        printarray(arr, top);
    }
}
void huffmancodes (char data[], int freq[], int n)
{
    struct node *root = huffmantree(data, freq, n);
    int arr[HEIGHT];
    int top = 0;
    
    printcodes(root, arr, top);
}

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    huffmancodes(arr, freq, size);

    return 0;
}
