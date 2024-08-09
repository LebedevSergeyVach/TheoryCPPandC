#include <stdio.h>
// Для чтения данных из .txt файла -> gcc main.c && ./a < assets/data.txt

/*
    Двухмерный массив
*/
int main()
{
    int row, column;
    printf("Enter ROW and COLUMN for two-dimensional array (row column): ");
    scanf("%d%d", &row, &column);

    // Создание двухмерного массива
    int a[row][column];

    // Инициализация данными двухмерного массива
    printf("\nEnter two-dimensional array:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Выведение в консоль двухмерного массива
    printf("\nTwo-dimensional array:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%3d, ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
