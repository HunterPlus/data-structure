#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* *array;
};
struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int**)malloc(
        capacity * sizeof(int*));
        
    return queue;
}
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
void enqueue(struct Queue *queue, int* item)
{
    if(isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", *item);
}
int* dequeue(struct Queue *queue)
{
    if(isEmpty(queue))
        return NULL;
    int* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
int* front(struct Queue *queue)
{
    if(isEmpty(queue))
        return NULL;
    return queue->array[queue->front];
}
int* rear(struct Queue *queue)
{
    if(isEmpty(queue))
        return NULL;
    return queue->array[queue->rear];
}

int main()
{
    int i;
    int *p;
    struct Queue *queue = createQueue(1000);
    for (i = 0; i < 50; i+=10){
        p = (int *)malloc(sizeof(int));
        *p = i + 10;
        enqueue(queue, p);
    }
    p = dequeue(queue);
    printf("%d dequeued from queue\n\n", p[0]);
    p = front(queue); 
    printf("Front item is %d\n", p[0]);
    p = rear(queue);
    printf("Rear item is %d\n", p[0]);    

    return 0;
}
