#include "student_stat.h"

int input(struct Student *students, int number);
void output(struct Student *students, int number);
void sort_student_mark(struct Student *students, int number);
void swap(int *a, int *b);

int input(struct Student *students, int number)
{
    int programm = 0;

    for (int i = 0; i < number; i++)
    {
        scanf("%20s", students[i].name);

        if (scanf("%d", &students[i].mark) != 1)
        {
            programm = 1;
        }
    }

    if (getchar() != '\n')
    {
        programm = 1;
    }

    return programm;
}

void output(struct Student *students, int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("Name: %s -> Mark %d", students[i].name, students[i].mark);
        if (i < number - 1)
        {
            printf("\n");
        }
    }
}

void sort_student_mark(struct Student *students, int number)
{
    for (int i = 0; i < number; i++)
    {
        int min_elenent = i;
        for (int j = i + 1; j < number; j++)
            if (students[j].mark < students[min_elenent].mark)
                min_elenent = j;
        swap(&students[min_elenent].mark, &students[i].mark);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
