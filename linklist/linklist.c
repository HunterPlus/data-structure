#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *newnode (int data);
void push (struct node **head, int data);
void insert (struct node **head, int data);
void delete (struct node **head, int key);
void delbypos (struct node **head, int pos);
struct node *reverse (struct node *head);
struct node *Rreverse (struct node *head);
int isloop (struct node *head);
void printlist (struct node *head);
/******************************************************************/
void insertionsort (struct node **head);
void sortedinsert (struct node **head, struct node *t);

void mergesort (struct node **t);
struct node* sortedmerge (struct node *t1, struct node *t2);
void split (struct node *s, struct node **t1, struct node **t2);
/***************************************************************/
struct node *newnode (int data)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->next = NULL;
    return t;
}
void push (struct node **head, int data)
{
    struct node *t = newnode(data);
    
    t->next = *head;
    *head = t;
}
void insert (struct node **head, int data)
{
    struct node *t = newnode(data);
    
    if (*head == NULL)
        *head = t;
    else
    {
        struct node *cur = *head;
        while (cur->next)
            cur = cur->next;
        cur->next = t;
    }
}

void delete (struct node **head, int key)
{
    struct node *tmp = *head, *prev;
    
    if (tmp && tmp->data == key)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }
    while (tmp && tmp->data != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}
void delbypos (struct node **head, int pos)
{
    if (*head == NULL)
        return;
    struct node *tmp = *head, *prev;
    
    if (pos == 0)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }
    while (tmp && pos--)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp != NULL)
    {
        prev->next = tmp->next;
        free(tmp);
    }
}
struct node *reverse (struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    
    struct node *p, *q, *r;
    p = head;
    q = r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}
struct node *Rreverse (struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
        
    struct node *rest = Rreverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return rest;
}
int isloop (struct node *head)
{
    struct node *slow = head, *fast = head;
    
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
            return 1;
    }
    return 0;
}
void printlist (struct node *head)
{
   while (head != NULL)
   {
       printf("%d ", head->data);
       head = head->next;
   }
}

/*******************************************************************/
void sortedinsert (struct node **head, struct node *t)
{
    struct node *cur = *head;

    if (*head == NULL || (*head)->data >= t->data)
    {
        t->next = *head;
        *head = t;
    } else
    {
        while (cur->next && cur->next->data < t->data)
            cur = cur->next;
        t->next = cur->next;
        cur->next = t;
    }
}
void insertionsort (struct node **head)
{
    struct node *sorted = NULL;
    struct node *p = *head, *q;
    
    while (p != NULL)
    {
        q = p;
        p = p->next;
        sortedinsert(&sorted, q);
    }
    *head = sorted;
}

void mergesort (struct node **t)
{
    struct node *s = *t;
    struct node *t1, *t2;
    
    if (s == NULL || s->next == NULL)
        return ;
        
    split(s, &t1, &t2);
    mergesort(&t1);
    mergesort(&t2);
    
    *t = sortedmerge(t1, t2);
    /*
    printf("\n-------------\n");
    printlist(*t);
    printf("\n-------------\n");   */
}
struct node* sortedmerge (struct node *t1, struct node *t2)
{
    struct node *result = NULL;
    
    if (t1 == NULL)
        return t2;
    else if (t2 == NULL)
        return t1;
    
    if (t1->data <= t2->data)
    {
        result = t1;
        result->next = sortedmerge(t1->next, t2);
    } else
    {
        result = t2;
        result->next = sortedmerge(t1, t2->next);
    }
    return result;
}
void split (struct node *s, struct node **t1, struct node **t2)
{
    struct node *slow, *fast;
    slow = s;
    fast = s->next;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *t1 = s;
    *t2 = slow->next;
    slow->next = NULL;
    /*
    printf("\n");
    printlist(*t1);
    printf("\n");
    printlist(*t2);   */
}

/********************************************************************/

int main()
{
    struct node* head = NULL;
  
    push(&head, 19);
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
    
    //insertionsort(&head);
    mergesort(&head);
  
    printf("\nCreated Linked List: \n");
    printlist(head);
    
    delbypos(&head, 1);
    printf("\nLinked List after Deletion at position 1: \n");
    printlist(head);
    
    delete(&head, 8);
    insert(&head, 15);
    printf("\n");
    printlist(head);
    
    printf("\n");
    printlist(reverse(head));

    return 0;
}
