#include <stdio.h>

/*
    Файлы

    С потоками работают стандартные функции языка С scanf, printf, fread, fwrite и другие.
    С файловыми дескрипторами работают системные вызовы ОС read, write и прочие.
    Не смешивайте в одном коде стандартные функции по работе с вводом/выводом и системные вызовы.


    | Файловый дескриптор | Поток  | Название                                        | Cвязан с    |
    | 0                   | stdin  | стандартный поток ввода (input)                 | клавиатурой |
    | 1	                  | stdout | поток вывода (output)	                         | терминалом  |
    | 2	                  | stderr | стандартный поток сообщений об ошибках (errors) | терминалом  |


    hello.exe > out.txt	        при запуске программы hello.exe перенаправить stdout в файл out.txt (перезаписать файл)
    hello.exe >> out.txt	    при запуске программы hello.exe дописать stdout в конец файла out.txt
    hello.exe < data.txt	    при запуске программы на stdin подать содержимое файла data.txt
    hello.exe | convert.exe	    запустить две программы, перенаправив stdout первой программы hello.exe на stdin второй


    Команда	                    Что делает
    gcc hello.c 2>&1 | less	    вывести сообщения об ошибках постранично
    hello.exe | grep ERROR	    отфильтровать только строки, содержащие ERROR
    hello.exe | sort	        отсортировать вывод
    hello.exe | wc	            подсчитать количество строк, слов и символов в выводе


    Открытие и закрытие потока

    FILE *fopen(const char *pathname, const char *mode);
    FILE *fdopen(int fd, const char *mode);
    FILE *freopen(const char *pathname, const char *mode, FILE *stream);
    fclose();

    path - путь к файлу
    mode - как этот файл открываем (режим открытия файла)


    Функция	                    Что делает
    fopen	                    Открывает файл path способом mode
    fdopen	                    Дооткрывает файловый дескриптор fd до потока способом mode
    freopen	                    Закрывает поток stream. Открывает файл path способом mode


    mode - режим открытия файла

    mode	         сокращение от	          значение
    "r"	             read                     чтение
    "w"	             write                    запись (обрезать файл до 0 длины)
    "a"	             append                   запись (в конец файла)
    "r+"	         rw                       чтение и запись (длина файла обрезается до 0)
    "w+"	         rw                       то же самое
    "a+"	         ra                       чтение из файла и запись (в конец файла)


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

int main()
{
    // Создание двух потоков: на чтение (-r) файла data.txt и перезапись (-w) файла out.txt
    const char *filename = "data.txt";
    FILE *file_open = fopen("assets/data.txt", "r"); // открыть файл data.txt на чтение - поток file_open
    FILE *file_out = fopen("assets/out.txt", "w");   // открыть файл out.txt на запись - поток

    // Проверка файла data.txt на содержание
    if (file_open == NULL)
    {
        // Остановит программу и выдаст ошибку, например -> Error open files!: No such file or directory
        perror("Error open files!");
        fprintf(stderr, "No open files: %s\n", filename);
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

    fprintf(file_out, "Sum numbers file %s = %d\n", filename, sum); // результат пишем в поток file_out

    // Закрытие открытых потоков для чтения файла data.txt и перезаписи файла out.txt
    fclose(file_open);
    fclose(file_out);

    return 0;
}
