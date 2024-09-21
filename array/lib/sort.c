#include "sort.h"

/*
    Функции для Быстрой сортировки (Quick Sort)
*/
int quickSortArray(int *array, int size);
int quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);

/*
    Функции для Сортировки слиянием (Merge Sort)
*/
int mergeSortArray(int *array, int size);
int mergeSort(int *array, int left, int right);
int merge(int *array, int left, int middle, int right);

/*
    Функции для Пирамидальной сортировки (Heap Sort):
*/
int heapSortArray(int *array, int size);
void heapify(int *array, int size, int i);
int heapSort(int *array, int size);

// Основная функция сортировки (Quick Sort)
int quickSortArray(int *array, int size)
{
    if (array == NULL || size <= 0)
    {
        return 0; // Возвращаем 0, если массив пустой или указатель на массив равен NULL
    }

    quickSort(array, 0, size - 1);

    return 1; // Возвращаем 1, если сортировка прошла успешно
}

// Рекурсивная функция Quick Sort
int quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }

    return 1;
}

// Функция для разделения массива
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            // Обмен значениями
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Обмен значениями
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

// Основная функция сортировки (Merge Sort)
int mergeSortArray(int *array, int size)
{
    if (array == NULL || size <= 0)
    {
        return 0; // Возвращаем 0, если массив пустой или указатель на массив равен NULL
    }

    mergeSort(array, 0, size - 1);

    return 1; // Возвращаем 1, если сортировка прошла успешно
}

// Рекурсивная функция Merge Sort
int mergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }

    return 1;
}

// Функция для слияния двух подмассивов
int merge(int *array, int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Создаем временные массивы
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
    {
        return 0; // Возвращаем 0, если не удалось выделить память
    }

    // Копируем данные во временные массивы L[] и R[]
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];

    for (j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    // Слияние временных массивов обратно в array[left..right]
    i = 0;    // Начальный индекс первого подмассива
    j = 0;    // Начальный индекс второго подмассива
    k = left; // Начальный индекс объединенного подмассива

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если есть
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если есть
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);

    return 1;
}

// Основная функция сортировки
int heapSortArray(int *array, int size)
{
    if (array == NULL || size <= 0)
    {
        return 0; // Возвращаем 0, если массив пустой или указатель на массив равен NULL
    }

    heapSort(array, size);

    return 1; // Возвращаем 1, если сортировка прошла успешно
}

// Функция для преобразования в двоичную кучу поддерева с корневым узлом i
void heapify(int *array, int size, int i)
{
    int largest = i;       // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;  // Левый = 2*i + 1
    int right = 2 * i + 2; // Правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (left < size && array[left] > array[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < size && array[right] > array[largest])
        largest = right;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        int swap = array[i];
        array[i] = array[largest];
        array[largest] = swap;

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(array, size, largest);
    }
}

// Основная функция для сортировки массива с использованием Heap Sort
int heapSort(int *array, int size)
{
    // Построение кучи (перегруппируем массив)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = size - 1; i > 0; i--)
    {
        // Перемещаем текущий корень в конец
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // вызываем heapify на уменьшенной куче
        heapify(array, i, 0);
    }

    return 1;
}
