#if defined(one)
#include <stdio.h> // gcc -Wall -Wextra -Done main.c

int inc(int x)
{
    return x + 1;
}

#elif defined(two)
#include <stdio.h> // gcc -Wall -Wextra -Dtwo main.c

int inc(int x)
{
    return x + 2;
}

#elif defined(three)
#include <stdio.h> // gcc -Wall -Wextra -Dthree main.c

int inc(int x)
{
    return x + 3;
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

int inc(int x)
{
    return x + 5;
}
