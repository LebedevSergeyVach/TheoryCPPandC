#include <stdio.h>

int main()
{
    return 0;
}

// Строки
int string()
{
    // Использование массива символов:
    char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char str2[] = "Hello"; // Компилятор автоматически добавляет '\0'

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    // Использование указателей
    char *str = "Hello";
    printf("str: %s\n", str);

    // strlen: Возвращает длину строки
    char str3[] = "Hello";
    int length = strlen(str3);
    printf("Length of '%s' is %d\n", str3, length);

    // strcpy: Копирует строку из одного места в другое
    char src4[] = "Hello";
    char dest[10];
    strcpy(dest, src4);
    printf("Copied string: %s\n", dest);

    // strcat: Объединяет две строки
    char str5[20] = "Hello";
    char str6[] = " World";
    strcat(str5, str6);
    printf("Concatenated string: %s\n", str5);

    // strcmp: Сравнивает две строки
    char str7[] = "Hello";
    char str8[] = "Hello";

    if (strcmp(str7, str8) == 0)
    {
        printf("Strings are equal\n");
    }
    else
    {
        printf("Strings are not equal\n");
    }

    return 0;
}
