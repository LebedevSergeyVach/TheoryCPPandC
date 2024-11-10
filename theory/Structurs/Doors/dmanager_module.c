#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

void initialize_doors(struct door *doors);
void doors_id_sorted(struct door *doors);
void doors_status_closed(struct door *doors);
void swap(int *a, int *b);
void doors_output(struct door *doors);

int main()
{
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    doors_id_sorted(doors);
    doors_status_closed(doors);
    doors_output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors)
{
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void doors_id_sorted(struct door *doors)
{
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        int min_element = i;
        for (int j = i + 1; j < DOORS_COUNT; j++)
            if (doors[j].id < doors[min_element].id)
                min_element = j;
        swap(&doors[min_element].id, &doors[i].id);
    }
}

void doors_status_closed(struct door *doors)
{
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        doors[i].status = 0;
    }
}

void swap(int *a, int *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void doors_output(struct door *doors)
{
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        printf("%d, %d", doors[i].id, doors[i].status);

        if (i < DOORS_COUNT - 1)
        {
            printf("\n");
        }
    }
}
