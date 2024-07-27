#include <stdio.h>

/* Циклы for и while*/
int main()
{
    // [i, 5]
    for (int i = 0; i <= 5; i++)
    {
        printf("Iteration %d\n", i);
    }

    int j = 0;
    // [i, 5]
    while (j <= 5)
    {
        printf("While iteration %d\n", j);
        j++;
    }

    return 0;
}
