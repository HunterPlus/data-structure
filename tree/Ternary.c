#include <stdio.h>
#include <stdlib.h>

#define MAX     50

struct node
{
    char ch;
    int eow;    // is End of Word
    struct node *l, *eq, *r;
};

struct node *newnode (char ch)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    
    t->ch = ch;
    t->eow = 0;
    t->l = t->eq = t->r = NULL;
    
    return t;
}
void insert (struct node **root, char *word)
{
    if (*root == NULL)
        *root = newnode(*word);
        
    if ((*word) < (*root)->ch)
        insert(&(*root)->l, word);
    else if ((*word) > (*root)->ch)
        insert(&(*root)->r, word);
    else 
    {
        if (*(word+1))
            insert(&(*root)->eq, word+1);
        else
            (*root)->eow = 1;
    }
}
void traverseutil (struct node *root, char buffer[], int depth)
{
    if (root)
    {
        traverseutil(root->l, buffer, depth);
        
        buffer[depth] = root->ch;
        if (root->eow == 1)
        {
            buffer[depth+1] = '\0';
            printf("%s\n", buffer);
        }
        traverseutil(root->eq, buffer, depth+1);
        
        traverseutil(root->r, buffer, depth);
    }
}
void traverse (struct node *root)
{
    char buffer[MAX];
    traverseutil(root, buffer, 0);
}
int search (struct node *root, char *word)
{
    if (root == NULL)
        return 0;
        
    if (*word < root->ch)
        return search(root->l, word);
        
    if (*word > root->ch)
        return search(root->r, word);
        
    if (*(word+1) == '\0')
        return root->eow;
        
    return search(root->eq, word+1);
}
int main()
{
    struct node *root = NULL;
    
    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");
    insert(&root, "best");
    
    printf("traversal of ternary search tree\n");
    traverse(root); 
    
    printf("\nsearch results for cats, bu and cat respectively\n");
    search(root, "cats")? printf("Found\n"): printf("Not Found\n");
    search(root, "bu")?   printf("Found\n"): printf("Not Found\n");
    search(root, "cat")?  printf("Found\n"): printf("Not Found\n");

    return 0;
}
