#include "include_define.h"

#include "sort.h"
#include "array_io.h"

int main()
{
    int programm = 0;

    printf("Enter array int (end: -1): ");

    int size;
    int *array = inputDynamicArrayWhileMinusOneInt(&size);

    if (array == NULL)
    {
        programm = 1;
    }
    else
    {
        printf("1 - Quick Sort\n2 - Merge Sort\n3 - Heap Sort\nEnter number: ");
        int operationMode;

        if (scanf("%d", &operationMode) != 1 || getchar() != '\n')
        {
            programm = 1;
        }
        else
        {
            char *nameSort;

            if (operationMode == 1)
            {
                quickSortArray(array, size);
                nameSort = "Quick sorted array";
            }
            else if (operationMode == 2)
            {
                mergeSortArray(array, size);
                nameSort = "Merge sorted array";
            }
            else if (operationMode == 3)
            {
                heapSortArray(array, size);
                nameSort = "Heap sorted array";
            }
            else
            {
                programm = 1;
                printf("You daun ?!\n");
                nameSort = "No sorted array";
            }

            printf("%s: ", nameSort);
            outputDynamicArrayInt(array, size);
        }
    }

    if (programm != 0)
    {
        printf("\nERROR\n");
    }

    free(array);

    return programm;
}
