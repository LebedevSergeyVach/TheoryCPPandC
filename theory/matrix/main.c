#include "lib/matrix_io.h"

/**
 * Компиляция GCC: `gcc main.c lib/matrix_io.c` или для проверки `gcc -Wall -Werror -Wextra  main.c lib/matrix_io.c`
 * cppcheck: `cppcheck --enable=all --suppress=missingIncludeSystem main.c lib/matrix_io.c`
 * valgrind: `valgrind --tool=memcheck --leak-check=yes -s ./a.out`
 */
int main()
{
    Matrix_NxM matrix;

    printf("\n===== Запуск ввода размеров для матрицы. =====\n");
    inputValueRowsAndColumns(&matrix);

    printf("\n===== Запуск инициализации матрицы. =====\n");
    InitMatrix(&matrix);

    // printf("Запуск ввода данных для матрицы.\n");
    // inputMatrix(&matrix);

    // printf("\n===== Запуск автоматического ввода случайных данных для матрицы. =====\n");
    // fillMatrixRandom(&matrix);

    printf("\n===== Запуск ввода данных для матрицы из файла. =====\n");
    if (readingMatrixFromFile(&matrix, "assets/matrix_one.txt"))
    {
        printf("\n===== Запуск вывода матрицы. =====\n");
        printf("\nМатрица %d на %d:\n", matrix.rows, matrix.columns);
        PrintMatrix(&matrix);

        printf("\n===== Запуск поиска индекса элемента по его двумерному индексу в матрице. =====\n");
        int i = 1, j = 1;
        int indexItem = searchingForElementIndexDynamicMatrix(&matrix, i, j);
        printf("По двумерному индексу [%d][%d], индекс элемента в динамическом массиве = %d (индекс в данных: %d), а данные = %.2lf\n",
               i, j, indexItem, indexItem - matrix.rows, *(matrix.pointerDynamicMatrix[0] + indexItem - matrix.rows));
    }

    printf("\n===== Запуск очистки выделенной памяти для матрицы. =====\n");
    freeMatrix(&matrix);

    return 0;
}
