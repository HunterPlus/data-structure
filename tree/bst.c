#include <stdio.h>
#include <stdlib.h>

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
        printf("%d \n", root->key);
        inorder(root->right);
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
    
    struct node* t = search(root, 70);
    printf("\nsearch: %d\n", t->key);
    
    return 0;
}
