#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
    Файлы

    С потоками работают стандартные функции языка С scanf, printf, fread, fwrite и другие.
    С файловыми дескрипторами работают системные вызовы ОС read, write и прочие.
    Не смешивайте в одном коде стандартные функции по работе с вводом/выводом и системные вызовы.


    | Файловый дескриптор | Поток  | Название                                        | Cвязан с    |
    | 0                   | stdin  | стандартный поток ввода (input)                 | клавиатурой |
    | 1	                  | stdout | поток вывода (output)                           | терминалом  |
    | 2	                  | stderr | стандартный поток сообщений об ошибках (errors) | терминалом  |


    hello.exe > out.txt         при запуске программы hello.exe перенаправить stdout в файл out.txt (перезаписать файл)
    hello.exe >> out.txt        при запуске программы hello.exe дописать stdout в конец файла out.txt
    hello.exe < data.txt        при запуске программы на stdin подать содержимое файла data.txt
    hello.exe | convert.exe     запустить две программы, перенаправив stdout первой программы hello.exe на stdin второй


    Команда                     Что делает
    gcc hello.c 2>&1 | less     вывести сообщения об ошибках постранично
    hello.exe | grep ERROR      отфильтровать только строки, содержащие ERROR
    hello.exe | sort            отсортировать вывод
    hello.exe | wc              подсчитать количество строк, слов и символов в выводе


    Открытие и закрытие потока

    FILE *fopen(const char *pathname, const char *mode);
    FILE *fdopen(int fd, const char *mode);
    FILE *freopen(const char *pathname, const char *mode, FILE *stream);
    fclose();

    path - путь к файлу
    mode - как этот файл открываем (режим открытия файла)


    Функция                     Что делает
    fopen                       Открывает файл path способом mode
    fdopen                      Дооткрывает файловый дескриптор fd до потока способом mode
    freopen                     Закрывает поток stream. Открывает файл path способом mode


    mode - режим открытия файла

    mode             сокращение от            значение
    "r"              read                     чтение
    "w"              write                    запись (обрезать файл до 0 длины)
    "a"              append                   запись (в конец файла)
    "r+"             rw                       чтение и запись (длина файла обрезается до 0)
    "w+"             rw                       то же самое
    "a+"             ra                       чтение из файла и запись (в конец файла)


    Если нам нужно читать не текстовый поток, а например картинку или видео, в котором последовательность
    \r\n должна быть сохранена, мы должны указать b (binary) режим, который отключит данное преобразование.
    Буква b может быть добавлена к любому упомянутому режиму, например "rb" или "wb+".
    В остальных ОС, кроме Windows, символ 'b' в этом аргументе просто игнорируется


    EOF - достигнут конец файла
    Когда в файле, открытом на чтение, закончились данные, то поток переходит в состояние EOF (End Of File, конец файла).

    Функция feof проверяет, находится ли поток stream в состоянии EOF или нет.
    Возвращает 1, если достигнуто состояние EOF, иначе возвращает 0.

    int feof(FILE * stream);
*/

// Определение структуры TimeIsNow, которая содержит поля для часов, минут и секунд
typedef struct TimeIsNow
{
    int hours, minuts, seconds;
} TimeIsNow;

// Определение структуры DataIsNow, которая содержит поля для дней, месяцев и лет
typedef struct DataIsNow
{
    int days, months, years;
} DataIsNow;

// Функция для получения текущего времени и записи его в структуру TimeIsNow
// Параметр TimeIsNow *time_now: Это указатель на структуру TimeIsNow
void getTimeIsNow(TimeIsNow *time_now);

// Функция для получения текущей даты и записи его в структуру DataIsNow
// Параметр DataIsNow *data_now: Это указатель на структуру DataIsNow
void getDataIsNow(DataIsNow *data_now);

// Функция для выводав в файл времени и даты из структур TimeIsNow и DataIsNow в формате ======= | дд:мм:гггг | чч:мм:сс | =======
void addTimeAndDataIsNowFiles(FILE *file, TimeIsNow time, DataIsNow data);

// Функция для выводав в терминал времени и даты из структур TimeIsNow и DataIsNow в формате ===== | дд:мм:гггг | чч:мм:сс | =====
void printTimeAndDataIsNow(TimeIsNow time, DataIsNow data);

// Функция для чтения файла с числами и поиска их суммы
int file_numbers();

int main()
{
    // Создание двух потоков: на чтение (-r) файла data.txt и перезапись (-w) файла out.txt
    const char *filenameOpen = "data.txt";
    const char *filenameClose = "out.txt";
    FILE *file_open = fopen("assets/data.txt", "r"); // открыть файл data.txt на чтение - поток file_open
    FILE *file_out = fopen("assets/out.txt", "a");   // открыть файл out.txt на запись - поток

    // Проверка файла data.txt на содержание
    if (file_open == NULL)
    {
        // Закрытие открытых потоков для чтения файла data.txt и перезаписи файла out.txt
        fclose(file_open);
        fclose(file_out);
        // Остановит программу и выдаст ошибку, например -> Error open files!: No such file or directory
        perror("Error open files!");
        fprintf(stderr, "No open files: %s\n", filenameOpen);
        // Возвращаем не 0, тк код не выполнился
        return 1;
        // Выводим ошибку компиляции, нельзя использовать в главной функции - main
        // exit(errno);
    }

    // Получаем текущее время и дату
    TimeIsNow current_time;
    getTimeIsNow(&current_time);

    DataIsNow current_data;
    getDataIsNow(&current_data);

    // Выводим в терминал дату и время
    printTimeAndDataIsNow(current_time, current_data);

    // Записываем текущее время и дату в файл out.txt
    addTimeAndDataIsNowFiles(file_out, current_time, current_data);

    // Объявляем переменную для хранения считанного символа
    char ch;

    // Работа с потоками (файлами)
    // Читаем файл посимвольно, EOF - достигнут конец файла
    while ((ch = fgetc(file_open)) != EOF)
    {
        // Выводим символ в консоль
        putchar(ch);

        // Записываем символ в выходной файл
        fputc(ch, file_out);
    }

    // Добавляем символ новой строки в конце записи файла
    fputc('\n', file_out);
    fprintf(file_out, "-----------------------------------------\nThe data is copied from the %s file to the %s file.\n", filenameOpen, filenameClose);

    printf("\n-----------------------------------------\nThe data is copied from the %s file to the %s file.\n", filenameOpen, filenameClose);

    // Закрытие открытых потоков для чтения файла data.txt и перезаписи файла out.txt
    fclose(file_open);
    fclose(file_out);

    return 0;
}

// Функция для получения текущего времени и записи его в структуру TimeIsNow
// Параметр TimeIsNow *time_now: Это указатель на структуру TimeIsNow
void getTimeIsNow(TimeIsNow *time_now)
{
    // Получаем текущее время в виде количества секунд с начала эпохи (1 января 1970 года)
    time_t current_time;
    time(&current_time);

    // Преобразуем время в структуру tm, которая содержит компоненты даты и времени
    struct tm *local_time = localtime(&current_time);

    // Записываем часы, минуты и секунды в поля структуры time_now
    // Оператор -> используется для доступа к полям структуры через указатель
    time_now->hours = local_time->tm_hour;
    time_now->minuts = local_time->tm_min;
    time_now->seconds = local_time->tm_sec;
}

// Функция для получения текущей даты и записи его в структуру DataIsNow
// Параметр DataIsNow *data_now: Это указатель на структуру DataIsNow
void getDataIsNow(DataIsNow *data_now)
{
    // Получаем текущее время в виде количества секунд с начала эпохи (1 января 1970 года)
    time_t current_time;
    time(&current_time);

    // Преобразуем время в структуру tm, которая содержит компоненты даты и времени
    struct tm *local_time = localtime(&current_time);

    // Записываем день, месяц и год в поля структуры data_now
    // Оператор -> используется для доступа к полям структуры через указатель
    data_now->days = local_time->tm_mday;
    data_now->months = local_time->tm_mon;
    data_now->years = local_time->tm_year + 1900;
}

// Функция для вывода времени из структур TimeIsNow и DataIsNow в формате чч:мм:сс
void addTimeAndDataIsNowFiles(FILE *file, TimeIsNow time, DataIsNow data)
{
    // Записываем время в формате чч:мм:сс с ведущими нулями для однозначных чисел
    fprintf(file, "\n======= | %02d:%02d:%04d | %02d:%02d:%02d | =======\n", data.days, data.months, data.years, time.hours, time.minuts, time.seconds);
}

// Функция для выводав в терминал времени и даты из структур TimeIsNow и DataIsNow в формате ===== | дд:мм:гггг | чч:мм:сс | =====
void printTimeAndDataIsNow(TimeIsNow time, DataIsNow data)
{
    // Выводим время в формате чч:мм:сс с ведущими нулями для однозначных чисел
    printf("===== | %02d:%02d:%04d | %02d:%02d:%02d |======\n", data.days, data.months, data.years, time.hours, time.minuts, time.seconds);
}

// Функция для чтения файла с числами и поиска их суммы
int file_numbers()
{
    // Создание двух потоков: на чтение (-r) файла data.txt и перезапись (-w) файла out.txt
    const char *filenameOpen = "data.txt";
    const char *filenameClose = "out.txt";
    FILE *file_open = fopen("assets/data.txt", "r");   // открыть файл data.txt на чтение - поток file_open
    FILE *file_out = fopen("assets/numbers.txt", "w"); // открыть файл out.txt на запись - поток

    // Проверка файла data.txt на содержание
    if (file_open == NULL)
    {
        // Остановит программу и выдаст ошибку, например -> Error open files!: No such file or directory
        perror("Error open files!");
        fprintf(stderr, "No open files: %s\n", filenameOpen);
        // Возвращаем не 0, тк код не выполнился
        return 1;
        // Выводим ошибку компиляции, нельзя использовать в главной функции - main
        // exit(errno);
    }

    // Работа с потоками (файлами)
    int n;
    fscanf(file_open, "%d", &n); // читаем количество чисел из потока file_open

    int i, sum;
    for (sum = 0, i = 0; i < n; i++)
    {
        int x;
        fscanf(file_open, "%d", &x); // читаем очередное число из потока file_open
        sum += x;
        printf("i=%d x=%d sum=%d\n", i, x, sum); // отладочная печать в поток stdout
    }

    fprintf(file_out, "Sum numbers file %s = %d\n", filenameOpen, sum); // результат пишем в поток file_out

    // Закрытие открытых потоков для чтения файла data.txt и перезаписи файла out.txt
    fclose(file_open);
    fclose(file_out);

    return 0;
}
