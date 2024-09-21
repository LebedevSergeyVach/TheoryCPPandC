#include <stdio.h>
// Для чтения данных из .txt файла -> gcc two_dimensional_array.c && ./a < assets/data.txt && rm a

/*
    Двухмерный массив или матрица
*/
int main()
{
    int rows, columns, sum = 0;
    printf("Enter ROW and COLUMN for two-dimensional array (rows columns): ");
    scanf("%d%d", &rows, &columns);

    // Создание двухмерного массива
    int a[rows][columns];

    // Инициализация данными двухмерного массива
    printf("\nEnter two-dimensional array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Выведение в консоль двухмерного массива
    printf("\nTwo-dimensional array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%3d, ", a[i][j]);
        }
        printf("\n");
    }

    // Посчитаем сумму всех значений внутри матрицы
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += a[i][j];
        }
    }

    printf("\nThe sum of all the values of the matrix = %d\n", sum);

    return 0;
}
