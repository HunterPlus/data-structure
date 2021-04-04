#include <stdio.h>
#include <stdlib.h>

void printArray (float arr[], int n);

struct node
{
    float data;
    struct node *next;
};
struct node* newNode (float data)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->next = NULL;
    
    return t;
}

void insertLink (struct node **head, float data)
{
    struct node* t = newNode(data);
    
    if (*head == NULL || (*head)->data >= t->data)
    {
        t->next = *head;
        *head = t;
    }
    else
    {
        struct node* q = *head;
        
        while (q->next != NULL && q->next->data < t->data)
            q = q->next;
            
        t->next = q->next;
        q->next = t;
    }
}

float exactLink(struct node **head)
{
    float x;
    x = (*head)->data;
    
    struct node *t = *head;
    *head = (*head)->next;
    free(t);
    
    return x;
}

void bucketSort (float arr[], int n)
{
    int i, j;
    
    struct node **b = (struct node**)malloc(n * sizeof(struct node*));
    for (i = 0; i < n; i++)
        b[i] = NULL;
    
    int h(int x) {return n * arr[x]; }
    
    for (i = 0; i < n; i++)
    {
        insertLink(&b[h(i)], arr[i]);
    }
    
    for (i=0,j=0; j < n; j++)
        while (b[j])
            arr[i++] = exactLink(&b[j]);
}

void printArray (float arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
        
    printf("\n");
}

int main()
{
    float arr[] = { 0.78, 0.17, 0.39, 0.26, 0.72, 0.66, 0.94, 0.34, 0.21, 0.14, 0.68, 0.33, 0.05 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    
    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}
