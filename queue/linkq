#include <stdio.h>
#include <stdlib.h>

struct Qnode {
    int key;
    struct Qnode *next;
};
struct Queue {
    struct Qnode *front;
    struct Qnode *rear;
};

struct Qnode *newnode(int k)
{
    struct Qnode *t = (struct Qnode*)malloc(sizeof(struct Qnode));
    t->key = k;
    t->next = NULL;
    return t;
}
struct Queue* createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, int k)
{
    struct Qnode *t = newnode(k);
    if(q->rear == NULL) {
        q->front = q->rear = t;
        return;
    }
    q->rear->next = t;
    q->rear = t;
}
int dequeue(struct Queue* q)
{
    int x = -1;
    if(q->front == NULL)
        return x;
    struct Qnode *t = q->front;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    x = t->key;
    free (t);
    return x;
}

int main()
{
    struct Queue* q = createQueue(); 
    enqueue(q, 10); 
    enqueue(q, 20); 
    dequeue(q); 
    dequeue(q); 
    enqueue(q, 30); 
    enqueue(q, 40); 
    enqueue(q, 50); 
    dequeue(q); 
    printf("Queue Front : %d \n", q->front->key); 
    printf("Queue Rear : %d", q->rear->key); 

    return 0;
}
