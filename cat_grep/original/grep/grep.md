# GREP

Команда `grep` (от "global regular expression print") используется для поиска строк в файлах, соответствующих заданному шаблону. 
Она поддерживает регулярные выражения, что позволяет выполнять сложные поисковые запросы.

## Основные флаги `grep`

1. **`-i` (или `--ignore-case`)**: Игнорирует регистр при поиске.
   - Пример: `grep -i "hello" file.txt`

2. **`-v` (или `--invert-match`)**: Инвертирует совпадение, выводит строки, которые не соответствуют шаблону.
   - Пример: `grep -v "error" logfile.txt`

3. **`-c` (или `--count`)**: Выводит количество строк, соответствующих шаблону, вместо самих строк.
   - Пример: `grep -c "warning" logfile.txt`

4. **`-l` (или `--files-with-matches`)**: Выводит только имена файлов, содержащих совпадения, вместо самих строк.
   - Пример: `grep -l "error" *.log`

5. **`-n` (или `--line-number`)**: Выводит номера строк, содержащих совпадения.
   - Пример: `grep -n "error" logfile.txt`

6. **`-r` (или `--recursive`)**: Рекурсивно ищет в каталогах.
   - Пример: `grep -r "error" /var/log/`

7. **`-w` (или `--word-regexp`)**: Ищет только целые слова, соответствующие шаблону.
   - Пример: `grep -w "error" logfile.txt`

8. **`-x` (или `--line-regexp`)**: Ищет только строки, полностью соответствующие шаблону.
   - Пример: `grep -x "error" logfile.txt`

9. **`-A num` (или `--after-context=num`)**: Выводит `num` строк после совпадения.
   - Пример: `grep -A 2 "error" logfile.txt`

10. **`-B num` (или `--before-context=num`)**: Выводит `num` строк перед совпадением.
    - Пример: `grep -B 2 "error" logfile.txt`

11. **`-C num` (или `--context=num`)**: Выводит `num` строк до и после совпадения.
    - Пример: `grep -C 2 "error" logfile.txt`

12. **`-e pattern` (или `--regexp=pattern`)**: Позволяет указать несколько шаблонов для поиска.
    - Пример: `grep -e "error" -e "warning" logfile.txt`

13. **`-f file` (или `--file=file`)**: Использует шаблоны из файла для поиска.
    - Пример: `grep -f patterns.txt logfile.txt`

14. **`-o` (или `--only-matching`)**: Выводит только совпадающие части строк.
    - Пример: `grep -o "error" logfile.txt`

15. **`-q` (или `--quiet` или `--silent`)**: Не выводит результаты поиска, только возвращает статус (0, если найдено, 1, если не найдено).
    - Пример: `grep -q "error" logfile.txt`

16. **`-E` (или `--extended-regexp`)**: Использует расширенные регулярные выражения (как в `egrep`).
    - Пример: `grep -E "error|warning" logfile.txt`

17. **`-F` (или `--fixed-strings`)**: Ищет фиксированные строки (как в `fgrep`), игнорируя регулярные выражения.
    - Пример: `grep -F "error" logfile.txt`

18. **`-H` (или `--with-filename`)**: Выводит имена файлов перед каждым совпадением.
    - Пример: `grep -H "error" *.log`

19. **`-h` (или `--no-filename`)**: Не выводит имена файлов перед совпадениями.
    - Пример: `grep -h "error" *.log`

20. **`-s` (или `--no-messages`)**: Подавляет сообщения об ошибках, связанных с отсутствием файлов или недоступностью.
    - Пример: `grep -s "error" nonexistentfile.txt`

### Примеры использования

1. **Поиск строк, содержащих слово "error" в файле `logfile.txt`**:

   ```bash
   grep "error" logfile.txt
   ```

2. **Поиск строк, содержащих слово "error" или "warning" в файле `logfile.txt`**:

   ```bash
   grep -E "error|warning" logfile.txt
   ```

3. **Поиск строк, содержащих слово "error", и вывод двух строк после совпадения**:

   ```bash
   grep -A 2 "error" logfile.txt
   ```

4. **Поиск строк, содержащих слово "error", и вывод номеров строк**:

   ```bash
   grep -n "error" logfile.txt
   ```

5. **Поиск строк, содержащих слово "error", в каталоге `/var/log/` рекурсивно**:

   ```bash
   grep -r "error" /var/log/
   ```
