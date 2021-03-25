#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Heap
{
    int size;
    int capacity;
    int *a;
};
void swap (int *x, int *y) {int t = *x; *x = *y; *y = t;}

struct Heap *createHeap (int capacity)
{
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->a = (int*)malloc(capacity * sizeof(int));
}

void heapify (struct Heap *heap, int i)
{
    int min = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < heap->size && heap->a[l] < heap->a[min])
        min = l;
        
    if ( r < heap->size && heap->a[r] < heap->a[min])
        min = r;
        
    if (min != i)
    {
        swap(&heap->a[i], &heap->a[min]);
        heapify(heap, min);
    }
}
void insertHeap (struct Heap *heap, int key)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap has full!");
        return;
    }
    heap->a[heap->size++] = key;
    int j = heap->size - 1;
    while (j > 0 && heap->a[j] < heap->a[(j-1)/2])
    {
        swap(&heap->a[j], &heap->a[(j-1)/2]);
        j = (j-1) / 2;
    }
}

int extractHeap (struct Heap *heap)
{
    if (heap->size == 0)
        return INT_MAX;
    
    if (heap->size == 1)
    {
        heap->size--;
        return heap->a[0];
    }
    
    int x = heap->a[0];
    heap->size--;
    heap->a[0] = heap->a[heap->size];
    heapify(heap, 0);
    
    return x;
}

void decreaseKey (struct Heap *heap, int i, int val)
{
    heap->a[i] = val;
    
    while (i > 0 && heap->a[i] < heap->a[(i-1) / 2])
    {
        swap(&heap->a[i], &heap->a[(i-1) / 2]);
        i = (i-1) / 2;
    }
}

int deleteKey (struct Heap *heap, int i)
{
    int x = heap->a[i];
    
    decreaseKey(heap, i, INT_MIN);
    
    extractHeap(heap);
    
    return x;
}

void printHeap (struct Heap *heap)
{
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->a[i]);
    printf("\n");
}

int main ()
{
    int arr[] = {10, 28, 6, 9, 26, 13, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Heap *heap = createHeap(n);
    
    for (int i = 0; i < n; i++)
        insertHeap(heap, arr[i]);
        
    printHeap(heap);
    
    printf("%d\n", extractHeap(heap));
    printHeap(heap);
    printf("%d\n", deleteKey(heap, 3));
    printHeap(heap);
    
    return 0;
}
