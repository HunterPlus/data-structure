#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    struct node *next;
};
struct node *newnode (int data)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    
    t->d = data;
    t->next = NULL;
    return t;
}
void push (struct node **top, int data)
{
    struct node *t = newnode(data);
    
    t->next = *top;
    *top = t;
    return;
}
int pop (struct node **top) 
{
    struct node *t = *top;
    *top = t->next;
    int data = t->d;
    free(t);
    return data;
}
int peek (struct node *top) { return top->d; }

int isEmpty (struct node *top) { return top == NULL; }

void display (struct node *top)
{
    struct node *t = top;
    
    while (t != NULL)
    {
        printf("%d ", t->d);
        t = t->next;
    }
}

int main()
{
    struct node *top = NULL;
    
    push(&top, 11);
    push(&top, 22);
    push(&top, 33);
    push(&top, 44);
    
    display(top);
    
    pop(&top);
    pop(&top);
    printf("\n");
    display(top);

    return 0;
}
