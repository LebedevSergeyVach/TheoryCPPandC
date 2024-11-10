#include "array_io.h"

int *inputDynamicArrayWhileMinusOneInt(int *size);
void outputDynamicArrayInt(int *array, int size);

int *inputDynamicArrayWhileMinusOneInt(int *size)
{
    int *array = (int *)malloc(sizeof(int));

    if (array == NULL)
    {
        *size = 0;
        array = NULL;
    }
    else
    {
        int count = 0;
        int value;

        while (TRUE)
        {
            if (scanf("%d", &value) != 1)
            {
                *size = 0;
                array = NULL;
                break;
            }
            else
            {
                if (value == -1)
                {
                    break;
                }

                array = (int *)realloc(array, (count + 1) * sizeof(int));

                if (array == NULL)
                {
                    array = NULL;
                    break;
                }
                else
                {
                    array[count] = value;
                    count++;
                }
            }
        }

        *size = count;
    }

    return array;
}

void outputDynamicArrayInt(int *array, int size)
{
    if (array == NULL)
    {
        printf("ERROR: ARRAY = NULL\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d", array[i]);

            if (i < size - 1)
            {
                printf(" ");
            }
        }
    }
}
