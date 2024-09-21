// Функция для добавления значений в массив до получения -1
int *addToDynamicArray(int *size)
{
    int *array = (int *)malloc(sizeof(int)); // Инициализируем массив с размером 1
    if (array == NULL)
    {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }

    int count = 0; // Текущее количество элементов в массиве
    int value;

    while (1)
    {
        printf("Введите целое число (для завершения введите -1): ");
        scanf("%d", &value);

        if (value == -1)
        {
            break; // Завершаем цикл, если введено -1
        }

        // Если массив заполнен, увеличиваем его размер на один элемент
        array = (int *)realloc(array, (count + 1) * sizeof(int));
        if (array == NULL)
        {
            printf("Ошибка выделения памяти.\n");
            return NULL;
        }

        // Добавляем значение в массив
        array[count] = value;
        count++;
    }

    // Устанавливаем размер массива
    *size = count;

    return array;
}