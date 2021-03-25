#include <stdio.h>
#include <stdlib.h>

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

struct node {
    int key;
    struct node *left, *right;
};
struct node* newnode(int key)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->key = key;
    t->left = t->right = NULL;
    
    return t;
}
struct node* insert(struct node* root, int key)
{
    struct node* t = root;
    struct node* q = NULL;
    
    if (root == NULL)
        return newnode(key);
    while (t)
    {
        q = t;
        if (key < t->key)
            t = t->left;
        else if (key > t->key)
            t = t->right;
        else
            return root;
    }
    t = newnode(key);
    if (key < q->key)
        q->left = t;
    else
        q->right = t;
    
    return root;
}
struct node* Rinsert(struct node* root, int key)
{
    if (root == NULL)
        return newnode(key);
    if(key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
        
    return root;
}
struct node* search(struct node* root, int key)
{
    struct node* t = root;
    while (t)
    {
        if (key == t->key)
            return t;
        else if (key < t->key)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}

struct node* Rsearch(struct node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    
    return search(root->right, key);
}
struct node* minnode(struct node* node)
{
    struct node* current = node;
    while(current && current->left != NULL)
        current = current->left;
    
    return current;
}
struct node* deletenode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deletenode(root->left, key);
    else if (key > root->key)
        root->right = deletenode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* t = root->right;
            free(root);
            
            return t;
        }
        else if (root->right == NULL) {
            struct node* t = root->left;
            free(root);
            
            return t;
        }
        struct node* t = minnode(root->right);
        root->key = t->key;
        root->right = deletenode(root->right, t->key);
    }
    return root;
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void levelorder (struct node *root)
{
    struct Queue *q = createQ(100);
    struct node* t = root;
    
    while (t)
    {
        printf ("%d ", t->key);
        
        if (t->left)
            enQ(q, t->left);
        if (t->right)
            enQ(q, t->right);
        t = deQ(q);
    }
}

int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);  
    printf("\n");
    levelorder(root);
    
    return 0;
}
