#include "operation.h"
#include "postfix.h"
#include "stack.h"

int main() {
    char expression[MAX_SIZE];
    scanf("%99s", expression);

    plot_function(expression);

    return 0;
}
