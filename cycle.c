#include <stdio.h>

/* Циклы for, while и do while */
int main()
{
    // [i, 5]
    for (int i = 0; i <= 5; i++)
    {
        printf("Iteration %d\n", i);
    }

    int j = 0;
    // [j, 5]
    while (j <= 5)
    {
        printf("While iteration %d\n", j);
        j++;
    }

    // [i, 5]
    int i = 0;
    do {
        printf("Iteration %d\n", i);
        i++;
    } while (i <= 5);

    return 0;
}
