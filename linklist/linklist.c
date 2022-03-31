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

void mergesort (struct node **h);
struct node* sortedmerge (struct node *h1, struct node *h2);
void split (struct node *h1, struct node **h2);
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
struct node *reverse(struct node *head)
{
    struct node *temp, *rear;
    
    if ((temp = head) == NULL || (rear = head->next) == NULL)
        return head;
    head = reverse(head->next);
    temp->next = NULL;
    rear->next = temp;
    return head;
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

void mergesort (struct node **h)
{
    struct node *h1 = *h, *h2;
  
    
    if (h1 == NULL || h1->next == NULL)
        return ;
        
    split(h1, &h2);
    mergesort(&h1);
    mergesort(&h2);
    
    *h = sortedmerge(h1, h2);
    /*
    printf("\n-------------\n");
    printlist(*h);
    printf("\n-------------\n");   */
}
struct node* sortedmerge (struct node *h1, struct node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;
    
    if (h1->data <= h2->data)
    {
        h1->next = sortedmerge(h1->next, h2);
        return h1;
    } else
    {
        h2->next = sortedmerge(h1, h2->next);
        return h2;
    }
}
void split (struct node *h1, struct node **h2)
{
    struct node *slow, *fast;
    slow = h1;
    fast = h1->next;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *h2 = slow->next;
    slow->next = NULL;
    /*
    printf("\n");
    printlist(h1);
    printf("\n");
    printlist(*h2);   */
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
