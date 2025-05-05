#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_CHAR 10

// Является ли буквой
int isLetter(char symbol)
{
    return (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z');
}

// Является ли заглавной буквой
int isCapitalLetter(char symbol)
{
    return symbol >= 'A' && symbol <= 'Z';
}

// Является ли строчная буквой
int isLowercaseLetter(char symbol)
{
    return symbol >= 'a' && symbol <= 'z';
}

// Меняем строчную на заглавную
char changeLowercase(char symbol)
{
    if (isLowercaseLetter(symbol))
    {
        return symbol - 32;
    }

    return symbol;
}

// Меняем заглавную на строчную
char changeCapital(char symbol)
{
    if (isCapitalLetter(symbol))
    {
        return symbol + 32;
    }

    return symbol;
}

// Являеися концом предложения
int isSentenceEnd(char symbol)
{
    return symbol == '.' || symbol == '!' || symbol == '?';
}

// Является пробелом, табом и переходом на новую строку
int isSpace(char symbol)
{
    return symbol == ' ' || symbol == '\t' || symbol == '\n';
}

// Является ли знаком препинания
int isPunctuationMarks(char symbol)
{
    return symbol == '.' || symbol == '!' || symbol == '?' || symbol == ',' || symbol == ':' || symbol == ';';
}

// Удаляет char по иднексу и смещает весь массив влево после удаленного символа
void deleteChar(char *pointerText, int indexDeleteChar)
{
    for (int i = indexDeleteChar; pointerText[i] != '\0'; i++)
    {
        pointerText[i] = pointerText[i + 1];
    }
}

// Добавлет пробел и сдвигает все символы вправо начиная с indexAddSpaceChar
int addSpaceChar(char *pointerText, int indexAddSpaceChar)
{
    size_t len = strlen(pointerText);

    if (len >= MAX_ARRAY_CHAR - 2)
    {
        return 0;
    }

    for (int i = len; i >= indexAddSpaceChar; i--)
    {
        pointerText[i + 1] = pointerText[i];
    }

    pointerText[indexAddSpaceChar] = ' ';
    return 1;
}

// Коррекция пререданного массива через указатель
int correctText(char *pointerText)
{
    int isStartSentence = 1;
    int isStartText = 1;

    for (int i = 0; pointerText[i] != '\0'; i++)
    {
        if ((isSpace(pointerText[i]) && isStartText) || (isPunctuationMarks(pointerText[i]) && isStartText))
        {
            deleteChar(pointerText, i);
        }

        if (isLetter(pointerText[i]))
        {
            if (isStartSentence)
            {
                pointerText[i] = changeLowercase(pointerText[i]);
                isStartSentence = 0;
            }
            else
            {
                pointerText[i] = changeCapital(pointerText[i]);
            }

            isStartText = 0;
        }

        if (isSentenceEnd(pointerText[i]))
        {
            isStartSentence = 1;
        }

        if (isSpace(pointerText[i]) && isSpace(pointerText[i + 1]))
        {
            deleteChar(pointerText, i);
            i--;
            continue;
        }

        if (isSpace(pointerText[i]) && isPunctuationMarks(pointerText[i + 1]))
        {
            deleteChar(pointerText, i);
            i--;
            continue;
        }

        if (isPunctuationMarks(pointerText[i]) && !isSpace(pointerText[i + 1]))
        {
            if (!addSpaceChar(pointerText, i + 1))
            {
                return 0;
            }

            continue;
        }
    }

    return 1;
}

/**
 * Обработка текста введенного пользователем
 * • Текст вводится пользователем при запуске программы
 * • текст хранится в статическом массиве заданного размера (ограничение на размер вводимого текста)
 * • реализация функции коррекции текста:
 * 1) большая буква только в начале предложения или в начале текста,
 * 2) удаление нескольких пробелов, следующих подряд,
 * 3) удаление пробелов перед точкой и запятой,
 * 4) добавление пробела после знаков препинания.
 * • проверка корректности размера массива (при добавлении пробелом не должен быть превышен размер массива)
 */
int main()
{
    char mainArrayChar[MAX_ARRAY_CHAR];

    printf("Введите текст размером %d символов:\n", MAX_ARRAY_CHAR - 1);
    fgets(mainArrayChar, MAX_ARRAY_CHAR, stdin);

    if (correctText(mainArrayChar))
    {
        printf("%s\n", mainArrayChar);
    }
    else
    {
        printf("Произошла ошибка при корректировки текста, превышен максимальный размер массива при увеличении!\n");
    }

    return 0;
}
