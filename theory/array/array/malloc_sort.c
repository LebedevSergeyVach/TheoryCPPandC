#include <stdio.h>
#include <stdlib.h>

int input_array(int *array, int number);
void output_array(const int *array, int number);
void sotr_array(int *array, int number);
void swap(int *a, int *b);

int main()
{
    int programm = 0;

    int number;
    if (scanf("%d", &number) != 1 || getchar() != '\n')
    {
        programm = 1;
        printf("n/a");
    }
    else
    {
        int *array = (int *)malloc(number * sizeof(int));

        if (array == NULL)
        {
            programm = 1;
            printf("n/a");
        }
        else
        {
            int input = input_array(array, number);

            if (input != 0)
            {
                programm = 1;
                printf("n/a");
            }
            else
            {
                sotr_array(array, number);
                output_array(array, number);
            }
        }

        free(array);
    }

    return programm;
}

int input_array(int *array, int number)
{
    int programm = 0;

    for (int *p = array; p - array < number; p++)
    {
        scanf("%d", p);
    }

    if (getchar() != '\n')
    {
        programm = 1;
    }

    return programm;
}

void output_array(const int *array, int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("%d ", array[i]);
    }
}

// Selection Sort - Сортировка по выбору
void sotr_array(int *array, int number)
{
    for (int i = 0; i < number; i++)
    {
        int min_element = i;
        for (int j = i + 1; j < number; j++)
            if (array[j] < array[min_element])
                min_element = j;
        swap(&array[min_element], &array[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
