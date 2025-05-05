#include "lib/matrix_io.h"
#include "lib/matrix_math.h"

/**
 * Работа с матрицами NхM
 * • Структура Matrix_NxM для хранения данных
 * • Данные хранятся в виде одномерного динамического массива (реализовать вычисление индекса элемента по его двумерному индексу в матрице).
 * • Функция InitMatrix() задает размер и выделяет память.
 * • Функция PrintMatrix() выводит матрицу на экран в табличном виде
 * • Функции вычисления суммы, произведения, определителя и обратной матрицы (функции не печатать результат, а возвращают его)
 * • Исходная матрица должна заполняться из файла или случайными числами
 * • Вычисление определителя с использованием рекурсивной функции (разложение по строке)
 *
 * Компиляция GCC: `gcc main.c lib/matrix_io.c lib/matrix_math.c` или для проверки `gcc -Wall -Werror -Wextra  main.c lib/matrix_io.c lib/matrix_math.c`
 * cppcheck: `cppcheck --enable=all --suppress=missingIncludeSystem main.c lib/matrix_io.c lib/matrix_math.c`
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

    printf("\n===== Запуск математических функций для матрицы. =====\n");

    Matrix_NxM matrix1, matrix2, matrixAnswer;

    printf("\n===== Запуск ввода размеров для матрицы. =====\n");
    inputValueRowsAndColumns(&matrix1);
    printf("\n===== Запуск инициализации матрицы. =====\n");
    InitMatrix(&matrix1);

    printf("\n===== Запуск ввода размеров для матрицы. =====\n");
    inputValueRowsAndColumns(&matrix2);
    printf("\n===== Запуск инициализации матрицы. =====\n");
    InitMatrix(&matrix2);

    printf("\n===== Запуск ввода данных для матрицы из файла. =====\n");
    readingMatrixFromFile(&matrix1, "assets/matrix_three.txt");
    printf("\n===== Запуск ввода данных для матрицы из файла. =====\n");
    readingMatrixFromFile(&matrix2, "assets/matrix_four.txt");

    printf("\n===== Запуск расчета суммы матриц. =====\n");
    matrixAnswer = sumMatrices(&matrix1, &matrix2);
    PrintMatrix(&matrixAnswer);
    freeMatrix(&matrixAnswer);

    printf("\n===== Запуск расчета умножения матриц. =====\n");
    matrixAnswer = multiplyMatrices(&matrix1, &matrix2);
    PrintMatrix(&matrixAnswer);
    freeMatrix(&matrixAnswer);

    printf("\n===== Запуск расчета определителя матрицы. =====\n");
    printf("Determinant %lf\n", determinantMatrix(&matrix1));

    printf("\n===== Запуск расчета обратной матрицы. =====\n");
    matrixAnswer = inverseMatrix(&matrix1);
    PrintMatrix(&matrixAnswer);
    freeMatrix(&matrixAnswer);

    printf("\n===== Запуск очистки выделенной памяти для матрицы. =====\n");
    freeMatrix(&matrix1);
    freeMatrix(&matrix2);

    printf("\n===== Запуск создания матрицы с помощью функции Matrix_NxM createMatrix(int rows, int columns). =====\n");
    Matrix_NxM matrixCreate;
    matrixCreate = createMatrix(3, 3);
    fillMatrixRandom(&matrixCreate);
    PrintMatrix(&matrixCreate);
    freeMatrix(&matrixCreate);

    return 0;
}
