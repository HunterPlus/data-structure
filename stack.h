#include <stdio.h>

struct stack {
  int size;
  int top;
  char *data;
};

struct stack *st_create(size_t size){
  struct stack *st;
  st = (struct stack *)malloc(sizeof(stack));
  st->size = size;
  st->top = -1;
  st->data = (char *)malloc(size);
  return st;
}
void push(const struct stack *st, char c){
  if(st->top == st->size-1){
    printf("stack is full, could not push!");
    exit(1);
  }
  st->data[++st->top] = c;
}
char pop(const struct stack *st){
  
}
