#include <stdio.h>

// Функция, выводящая содержание массивы в консоль
void printArray(int arr[], int size);

/* Массивы */
int main()
{
    // Способы инициализации
    int a3[7];                                  // или "мусор" (локальный), или нули (глобальный, static)
    int a1[3] = {12, -6, 44};                   // a1[0] = 12, a1[1] = -6, a1[2] = 44;
    int a2[3] = {12, -6};                       // a2[0] = 12, a2[1] = -6, a2[2] = 0; оставшиеся нули
    int a4[8] = {0};                            // все элементы нули
    int a5[8] = {};                             // все элементы нули
    int a6[] = {12, -6, 44};                    // int a6[3] = {12, -6, 44};
    int a7[100] = {[77] = 6, [8] = 11};         // a7[77]=6, a7[8]=11, остальные нули
    int a8[100] = {[16 ... 18] = 6, [33] = 11}; // a8[16]=6, a8[17]=6, a8[18]=6, a8[33]=11, остальные нули

    // Инициализация массивы с указанием типа данных и длины
    int a[5];

    // Заполнение массива через консоль с помощью цикла for
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }

    // Выведение массива в консоль с помощью цикла for
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }

    /* Создание массива с использованием динамической памяти можно написать так: */
    int n;
    scanf("%d", &n);
    float *a = malloc(n * sizeof(float)); // выделяем динамическую память для размещения массива
    // обращаемся как с обычным массивом, доступ к элементу a[i]
    // ...
    free(a); // когда массив не нужен, освобождаем выделенную память

    return 0;
}

// Функция, выводящая содержание массивы в консоль
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
