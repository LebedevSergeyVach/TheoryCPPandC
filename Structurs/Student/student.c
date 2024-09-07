#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student_struct.h"
#include "student_stat.h"

int main()
{
    int programm = 0;
    int number;

    if (scanf("%d", &number) != 1 || getchar() != '\n')
    {
        programm = 1;
    }
    else
    {
        struct Student *students = malloc(number * sizeof(struct Student));

        if (students == NULL)
        {
            programm = 1;
        }
        else if (input(students, number) != 0)
        {
            programm = 1;
        }
        else
        {
            sort_student_mark(students, number);
            output(students, number);
        }

        free(students);
    }

    if (programm != 0)
    {
        printf("n/a");
    }

    return programm;
}
