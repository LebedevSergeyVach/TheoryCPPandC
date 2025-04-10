#include "matrix_io.h"

int InitMatrix(Matrix_NxM *matrix)
{
    double **pointerArray = (double **)malloc(matrix->rows * sizeof(double *) + matrix->rows * matrix->columns * sizeof(double));

    if (pointerArray == NULL)
    {
        perror("Не удалось создать матрицу");
        return 0;
    }

    double *tempPointer = (double *)(pointerArray + matrix->rows);

    for (int i = 0; i < matrix->rows; i++)
        pointerArray[i] = tempPointer + matrix->columns * i;

    matrix->pointerDynamicMatrix = pointerArray;

    return 1;
}

int freeMatrix(Matrix_NxM *matrix)
{
    if (matrix == NULL)
    {
        perror("Матрица не инициализирована!\n");
        return 0;
    }

    free(matrix->pointerDynamicMatrix);

    return 1;
}

int PrintMatrix(const Matrix_NxM *matrix)
{
    if (matrix == NULL)
    {
        perror("Матрица не инициализирована!\n");
        return 0;
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        printf("| ");

        for (int j = 0; j < matrix->columns; j++)
        {
            printf("%.2lf", matrix->pointerDynamicMatrix[i][j]);

            if (j < matrix->columns - 1)
                printf(" ");
        }

        printf(" |\n");
    }

    return 1;
}

int inputMatrix(Matrix_NxM *matrix)
{
    if (matrix == NULL)
    {
        perror("Матрица не инициализирована!\n");
        return 0;
    }

    while (1)
    {
        printf("Введите значения для матрицы, размером %d на %d: ", matrix->rows, matrix->columns);

        for (int i = 0; i < matrix->rows; i++)
        {
            for (int j = 0; j < matrix->columns; j++)
            {
                scanf("%lf", &matrix->pointerDynamicMatrix[i][j]);
            }
        }

        if (getchar() != '\n')
        {
            printf("Были введены неверные данные для матрицы!\n");
            while (getchar() != '\n')
                ;

            continue;
        }

        break;
    }

    return 1;
}

void inputValueInt(int *pointerValue, const char *descriptionValues)
{
    while (1)
    {
        printf("Введите значение для количества %s в матрице: ", descriptionValues);

        if (scanf("%d", pointerValue) != 1 || getchar() != '\n')
        {
            printf("Введено неверное значение!\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        break;
    }
}

int inputValueRowsAndColumns(Matrix_NxM *matrix)
{
    if (matrix == NULL)
    {
        perror("Матрица не инициализирована!\n");
        return 0;
    }

    while (1)
    {
        inputValueInt(&matrix->rows, "строк");

        if (matrix->rows < 1)
        {
            printf("Введено неверное значение для количества строк, должно быть > 1!\n");

            continue;
        }

        break;
    }

    while (1)
    {
        inputValueInt(&matrix->columns, "столбцов");

        if (matrix->columns < 1)
        {
            printf("Введено неверное значение для количества столбцов, должно быть > 1!\n");

            continue;
        }

        break;
    }

    return 1;
}

int fillMatrixRandom(Matrix_NxM *matrix)
{
    if (matrix == NULL)
    {
        perror("Матрица не инициализирована!\n");
        return 0;
    }

    srand(time(NULL));

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            matrix->pointerDynamicMatrix[i][j] = (double)rand();
        }
    }

    return 1;
}

int searchingForElementIndexDynamicMatrix(const Matrix_NxM *matrix, int row, int column)
{
    if (matrix == NULL)
    {
        perror("Матрица не инициализирована!\n");
        return 0;
    }

    if (row < 0 || row > matrix->rows || column < 0 || column > matrix->columns)
    {
        perror("Некорректные индексы элемента в матрице!\n");
        return 0;
    }

    return matrix->rows + row * matrix->columns + column;
}

int readingMatrixFromFile(Matrix_NxM *matrix, const char *pathToFile)
{
    if (matrix == NULL || pathToFile == NULL)
    {
        perror("Матрица или путь к файлу не инициализированы!\n");
        return 0;
    }

    FILE *file = fopen(pathToFile, "r");

    if (file == NULL)
    {
        perror("Не удалось открыть файл!\n");
        return 0;
    }

    int rows, columns;

    if (fscanf(file, "%d %d", &rows, &columns) != 2)
    {
        perror("Неверный формат файла - не удалось прочитать размеры матрицы!\n");
        fclose(file);
        return 0;
    }

    if (rows != matrix->rows || columns != matrix->columns)
    {
        fprintf(stderr, "Размеры матрицы в файле (%dx%d) не соответствуют текущей матрице (%dx%d)!\n",
                rows, columns, matrix->rows, matrix->columns);
        fclose(file);
        return 0;
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            if (fscanf(file, "%lf", &matrix->pointerDynamicMatrix[i][j]) != 1)
            {
                fprintf(stderr, "Не удалось прочитать элемент [%d][%d]!\n", i, j);
                fclose(file);
                return 0;
            }
        }
    }

    fclose(file);
    return 1;
}
