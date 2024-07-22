#ifdef xpp
#include <stdio.h> // gcc -Wall -Wextra -Dxpp main.c

int inc(int x)
{
    return x + 1;
}

#endif
#include <stdio.h>

int inc(int x);

int main()
{
    int x;
    x = inc(10);
    printf("%d", x);

    return 0;
}
