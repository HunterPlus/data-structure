#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *l, *r;
};
int min(int a, int b) { return (a < b) ? a : b; }

struct node *newnode(int data)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->l = t->r = NULL;

    return t;
}
int mindepth(struct node *x)
{
    if (x == NULL)
        return 0;

    return 1 + min(mindepth(x->l), mindepth(x->r));
}

int main()
{
    struct node *root = newnode(1);
    root->l = newnode(2);
    root->r = newnode(3);
    root->l->l = newnode(4);
    root->l->r = newnode(5);

    printf("The minimum depth of binary tree is: %d\n", mindepth(root));
    return 0;
}
