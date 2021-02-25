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
  
}
char pop(const struct stack *st){
  
}
