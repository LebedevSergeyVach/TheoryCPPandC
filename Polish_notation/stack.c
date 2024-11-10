#include "stack.h"

void push(Stack *s, double item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++(s->top)] = item;
    }
}

double pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    }
    return 0;
}
