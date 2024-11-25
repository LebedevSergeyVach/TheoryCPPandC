# Документация к директории **[grep](doc.md)**

## [GREP](.)

### Опции `grep`

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -e | Шаблон. |
| 2 | -i | Игнорирует различия регистра.  |
| 3 | -v | Инвертирует смысл поиска соответствий. |
| 4 | -c | Выводит только количество совпадающих строк. |
| 5 | -l | Выводит только совпадающие файлы.  |
| 6 | -n | Предваряет каждую строку вывода номером строки из файла ввода. |
| 7 | -h | Выводит совпадающие строки, не предваряя их именами файлов. |
| 8 | -s | Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах. |
| 9 | -f file | Получает регулярные выражения из файла. |
| 10 | -o | Печатает только совпадающие (непустые) части совпавшей строки. |

### [s21_flags_grep.h](s21_flags_grep.h)

```C
// Определение флагов для опций команды grep
#define FLAG_E 0x01 // Регулярное выражение
#define FLAG_I 0x02 // Игнорирование регистра
#define FLAG_V 0x04 // Инвертирование совпадений
#define FLAG_C 0x08 // Подсчет количества совпадений
#define FLAG_L 0x10 // Вывод только имен файлов с совпадениями
#define FLAG_N 0x20 // Вывод номеров строк
```

Каждый флаг представляет собой уникальный бит в целом числе. Нужно для комбинации флагов с помощью битовых операций. (16CC)

---

### [s21_options_grep.c](s21_options_grep.c)

#### `int parse_options(int argc, char *argv[], int *flags, char **pattern, int *program_execution)`

```C
#include "s21_options_grep.h"

int parse_options(int argc, char *argv[], int *flags, char **pattern, int *program_execution)
{
    // Определение длинных опций для getopt_long
    static struct option long_options[] = {
        {"regexp", required_argument, 0, 'e'},       // Опция -e с обязательным аргументом
        {"ignore-case", no_argument, 0, 'i'},        // Опция -i без аргумента
        {"invert-match", no_argument, 0, 'v'},       // Опция -v без аргумента
        {"count", no_argument, 0, 'c'},              // Опция -c без аргумента
        {"files-with-matches", no_argument, 0, 'l'}, // Опция -l без аргумента
        {"line-number", no_argument, 0, 'n'},        // Опция -n без аргумента
        {0, 0, 0, 0}                                 // Завершающий элемент
    };

    // Инициализация указателя на шаблон
    *pattern = NULL;

    // Переменная для хранения текущей опции
    int opt;

    // Цикл для парсинга опций командной строки
    while ((opt = getopt_long(argc, argv, "e:ivcln", long_options, NULL)) != -1)
    {
        switch (opt)
        {
        case 'e':
            *flags |= FLAG_E;  // Установка флага FLAG_E
            *pattern = optarg; // Сохранение шаблона из аргумента опции
            break;
        case 'i':
            *flags |= FLAG_I; // Установка флага FLAG_I
            break;
        case 'v':
            *flags |= FLAG_V; // Установка флага FLAG_V
            break;
        case 'c':
            *flags |= FLAG_C; // Установка флага FLAG_C
            break;
        case 'l':
            *flags |= FLAG_L; // Установка флага FLAG_L
            break;
        case 'n':
            *flags |= FLAG_N; // Установка флага FLAG_N
            break;
        default:
            error_used_command_grep(program_execution, argv[0]); // Вызов функции для обработки ошибки
            break;
        }
    }

    // Если произошла ошибка, сбрасываем индекс опций
    if (*program_execution)
    {
        optind = -1;
    }
    // Если шаблон не был указан с флагом -e, берем первый аргумент после флагов
    else if (*pattern == NULL && optind < argc)
    {
        *pattern = argv[optind++];
    }

    // Возвращаем индекс следующего аргумента после флагов
    return optind;
}
```

---

#### `struct option`

```C
struct option {
    const char *name;     // Имя длинной опции
    int         has_arg;  // Флаг, указывающий, требуется ли аргумент для этой опции
    int        *flag;     // Указатель на переменную, в которую будет записано значение, если flag не равен NULL
    int         val;      // Значение, которое будет возвращено или записано в *flag
};
```

```C
static struct option long_options[] = {
    {"regexp", required_argument, 0, 'e'},
    {"ignore-case", no_argument, 0, 'i'},
    {"invert-match", no_argument, 0, 'v'},
    {"count", no_argument, 0, 'c'},
    {"files-with-matches", no_argument, 0, 'l'},
    {"line-number", no_argument, 0, 'n'},
    {"show-filename", no_argument, 0, 't'},
    {0, 0, 0, 0}};
```

- **name**: Имя длинной опции. `"number-nonblank"`.
- **has_arg**: Флаг, указывающий, требуется ли аргумент для этой опции. Возможные значения:
  - `no_argument` (или 0): Опция не требует аргумента.
  - `required_argument` (или 1): Опция требует обязательного аргумента.
  - `optional_argument` (или 2): Опция может иметь необязательный аргумент.
- **flag**: Указатель на переменную, в которую будет записано значение, если `flag` не равен `NULL`. Если `flag` равен `NULL`, то функция вернет значение `val`.
- **val**: Значение, которое будет возвращено или записано в `*flag`.

`{0, 0, 0, 0}`: Завершающий элемент, указывающий на конец массива опций.

---

#### `getopt_long`

```C
int getopt_long(int argc, char *const argv[], const char *shortopts, const struct option *longopts, int *longindex);
```

- **argc**: Количество аргументов, переданных в `main`.
- **argv**: Массив аргументов, переданных в `main`.
- **shortopts**: Строка, содержащая короткие опции. Например, `"benstET"`.
- **longopts**: Массив структур `struct option`, описывающих длинные опции.
- **longindex**: Указатель на переменную, в которую будет записан индекс найденной длинной опции. Если не нужен, можно передать `NULL`.

---

Битовая операция |=
Оператор |= (битовое ИЛИ с присваиванием) используется для установки определенного бита в переменной flags.

---

Возвращает индекс следующего аргумента после флагов

---

### [s21_process_grep_file.c](s21_process_grep_file.c)

#### `void process_file_grep(int flags, const char *pattern, FILE *file, const char *filename, int file_count, int *program_execution)`

```C
void process_file_grep(int flags, const char *pattern, FILE *file, const char *filename, int file_count, int *program_execution)
{
    regex_t regex;

    // Флаги для компиляции регулярного выражения
    int regex_flags = REG_EXTENDED;

    if (flags & FLAG_I)
    {
        // Добавление флага игнорирования регистра, если указан флаг -i
        regex_flags |= REG_ICASE;
    }

    // Компиляция регулярного выражения
    if (regcomp(&regex, pattern, regex_flags) != 0)
    {
        fprintf(stderr, "Недопустимое регулярное выражение: %s\n", pattern);
        *program_execution = 1;
        return;
    }

    char line[MAX_LINE_LENGTH]; // Буфер для хранения строки
    int line_number = 0;        // Счетчик строк
    int match_count = 0;        // Счетчик совпадений
    int file_has_matches = 0;   // Флаг, указывающий, есть ли совпадения в файле

    // Чтение файла построчно
    while (fgets(line, sizeof(line), file))
    {
        line_number++;
        // Проверка совпадения строки с регулярным выражением
        int match = regexec(&regex, line, 0, NULL, 0) == 0;

        if ((flags & FLAG_V) ? !match : match)
        {
            // Инвертирование совпадения, если указан флаг -v
            if (flags & FLAG_L)
            {
                // Установка флага, если найдено совпадение и указан флаг -l
                file_has_matches = 1;
                // Прерывание цикла, так как достаточно найти хотя бы одно совпадение
                break;
            }
            if (flags & FLAG_C)
            {
                // Увеличение счетчика совпадений, если указан флаг -c
                match_count++;
            }
            else
            {
                if (file_count > 1)
                {
                    // Вывод имени файла, если файлов больше одного
                    printf(VIOLET "%s:\t " RESET, file == stdin ? "-" : filename);
                }
                if (flags & FLAG_N)
                {
                    printf(GREEN "%d:\t" RESET, line_number);
                }
                printf(RED "%s" RESET, line);
            }
        }
    }

    // Вывод количества совпадений, если указан флаг -c
    if (flags & FLAG_C)
    {
        if (file_count > 1)
        {
            // Вывод имени файла синим цветом, если файлов больше одного
            printf(VIOLET "%s:\t" RESET, file == stdin ? "-" : filename);
        }

        // Вывод количества совпадений красным цветом
        printf(RED "%d" RESET "\n", match_count);
    }

    // Вывод имени файла, если указан флаг -l и найдены совпадения
    if (flags & FLAG_L && file_has_matches)
    {
        printf(VIOLET "%s" RESET "\n", file == stdin ? "-" : filename);
    }

    // Освобождение ресурсов, занятых регулярным выражением
    regfree(&regex);
}

```

#### Аргументы функции

- `int flags`: Битовый флаг, указывающий, какие опции были переданы в программу.
- `const char *pattern`: Строка, содержащая регулярное выражение для поиска.
- `FILE *file`: Указатель на файл, который нужно обработать.
- `const char *filename`: Имя файла, который обрабатывается (используется для вывода).
- `int file_count`: Количество файлов, переданных в программу.
- `int *program_execution`: Указатель на переменную, которая указывает на состояние выполнения программы (0 - успешно, 1 - ошибка).

---

#### Компиляция регулярного выражения REGEX

```C
regex_t regex;

// Флаги для компиляции регулярного выражения
int regex_flags = REG_EXTENDED;

if (flags & FLAG_I)
{
    // Добавление флага игнорирования регистра, если указан флаг -i
    regex_flags |= REG_ICASE;
}
```

- `regex_t regex;` — объявление структуры для хранения регулярного выражения.
- `int regex_flags = REG_EXTENDED;` — установка флагов для компиляции регулярного выражения.
- `if (flags & FLAG_I) { regex_flags |= REG_ICASE; }` — добавление флага игнорирования регистра, если указан флаг `-i`.
- `regcomp(&regex, pattern, regex_flags)` — компиляция регулярного выражения. Если компиляция завершается неудачно, выводится сообщение об ошибке и функция завершается.

---

#### Цикл чтения файла `fgets`

```C
char *fgets(char *str, int n, FILE *stream);
```

- **`str`**: Указатель на буфер, в который будет записана прочитанная строка.
- **`n`**: Максимальное количество символов, которые будут прочитаны (включая завершающий нулевой символ).
- **`stream`**: Указатель на файл, из которого будет производиться чтение.

Используется для чтения файла построчно до тех пор, пока не будет достигнут конец файла (EOF).

```C
while (fgets(line, sizeof(line), file))
```

- `int match = regexec(&regex, line, 0, NULL, 0) == 0;` — проверка совпадения строки с регулярным выражением.

---

#### [doc.md](doc.md)
