#include "include_define.h"

#include "sort.h"
#include "array_io.h"

int main()
{
    int programm = 0;

    int size;
    int *array = inputDynamicArrayWhileMinusOneInt(&size);

    if (array == NULL)
    {
        programm = 1;
    }
    else
    {
        if (quickSortArray(array, size))
        {
            outputDynamicArrayInt(array, size);
        }
        else
        {
            programm = 1;
        }
    }

    if (programm != 0)
    {
        printf("ERROR");
    }

    free(array);
    return programm;
}
