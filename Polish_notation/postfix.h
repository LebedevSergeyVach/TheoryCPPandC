#ifndef POSTFIX_H
#define POSTFIX_H

#include "include_define.h"
#include "operation.h"
#include "stack.h"

void infix_to_postfix(char *infix, char *postfix);
double evaluate_postfix(char *postfix, double x);

#endif
