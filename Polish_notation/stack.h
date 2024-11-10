#ifndef STACK_H
#define STACK_H

#include "include_define.h"

typedef struct {
    double items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, double item);
double pop(Stack *s);

#endif
