# Документация к директории **[`common`](.)**

## [ERROR](.)

### [error.c](error.c)

#### `void error_check_file_exists(int *program_execution, int argc, char *argv[])`

```C
// Функция для проверки существования файлов, переданных в качестве аргументов
void error_check_file_exists(int *program_execution, int argc, char *argv[])
{
    for (int i = optind; i < argc; i++) {
        if (access(argv[i], F_OK) == -1) {
            fprintf(stderr, "Файл '%s' не существует или недоступен.\n", argv[i]);
            *program_execution = 1;

            break;
        }
    }
}
```

Предназначена для проверки существования файлов, переданных в качестве аргументов командной строки.

- `access(argv[i], F_OK) == -1`: Функция `access` проверяет, существует ли файл, указанный в `argv[i]`. Если файл не существует или недоступен, `access` вернет `-1`.
- `F_OK`: Это флаг, который указывает `access` проверить только существование файла.

---

#### [doc.md](doc.md)
