#ifndef OPERATION_H
#define OPERATION_H

#include "include_define.h"
#include "postfix.h"

int is_operator(char ch);
int precedence(char ch);
void plot_function(char *expression);

#endif
