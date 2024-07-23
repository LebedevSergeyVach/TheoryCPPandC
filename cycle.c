#include <stdio.h>

int main()
{
    return 0;
}

// Циклы
int cycle()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Iteration %d\n", i);
    }

    int j = 0;
    while (j < 5)
    {
        printf("While iteration %d\n", j);
        j++;
    }
}
