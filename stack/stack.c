#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = (int*)malloc(capacity * sizeof(int));
    return s;
}
int isFull(struct Stack* s)
{
    return s->top == s->capacity - 1;
}
int isEmpty(struct Stack* s)
{
    return s->top == -1;
}
void push(struct Stack* s, int item)
{
    if(isFull(s))
        return;
    s->array[++s->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* s)
{
    if(isEmpty(s))
        return INT_MIN;
    return s->array[s->top--];
}
int peek(struct Stack* s)
{
    if(isEmpty(s))
        return INT_MIN;
    return s->array[s->top];
}

int main()
{
    struct Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));

    return 0;
}
