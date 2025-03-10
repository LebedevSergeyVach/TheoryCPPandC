# Графический калькулятор с Польской нотацией
## Документация 

---

## Структура проекта

* **graph.c:** Основной файл программы, который принимает ввод пользователя и вызывает функцию для построения графика.

* **operation.c:** Содержит функции для определения операторов, определения приоритета операторов и построения графика функции.

* **operation.h:** Заголовочный файл для operation.c.

* **postfix.c:** Содержит функции для преобразования инфиксной записи в постфиксную и вычисления значения функции.

* **postfix.h:** Заголовочный файл для postfix.c.

* **stack.c:** Реализация стека для хранения данных.

* **stack.h:** Заголовочный файл для stack.c.

* **Makefile:** Файл для сборки проекта с помощью make.

---

## Функциональность

### Основные функции

#### Преобразование инфиксной записи в постфиксную:
* Функция **infix_to_postfix** преобразует введенное пользователем математическое выражение из инфиксной записи в постфиксную.

#### Вычисление значения функции:
* Функция **evaluate_postfix** вычисляет значение функции для заданного значения x на основе постфиксной записи.

#### Построение графика:
* Функция **plot_function** строит график функции на основе вычисленных значений и выводит его в консоль.

#### Поддерживаемые операции и функции:
* Операторы: +, -, *, /
* Функции: sin, cos, tan, ctg, sqrt, ln

---

## Подробная документация

### Файл graph.c

#### **int main()**

* Описание:** Основная функция программы, которая принимает ввод пользователя и вызывает функцию для построения графика.
* Входные данные:** Пользователь вводит математическое выражение в виде строки.
* Выходные данные:** График функции выводится в консоль.

### Файл operation.c()

#### **int is_operator(char ch)**

* **Описание:** Проверяет, является ли символ оператором.
* **Входные данные:** Символ ch.
* **Выходные данные:** Возвращает 1, если символ является оператором, иначе 0.

#### **int precedence(char ch)**

* **Описание:** Определяет приоритет оператора.
* **Входные данные:** Символ ch.
* **Выходные данные:** Возвращает целое число, представляющее приоритет оператора.

#### **void plot_function(char *expression)**

* **Описание:** Строит график функции на основе введенного выражения.
* **Входные данные:** Строка expression, содержащая математическое выражение.
* **Выходные данные:** График функции выводится в консоль.

### Файл operation.h

* **Описание:** Заголовочный файл, содержащий объявления функций и констант для operation.c.

### Файл postfix.c

#### **void infix_to_postfix(char *infix, char *postfix)**

* **Описание:** Преобразует инфиксную запись в постфиксную.
* **Входные данные:** Строка infix, содержащая инфиксное выражение.
* **Выходные данные:** Строка postfix, содержащая постфиксное выражение.

#### **double evaluate_postfix(char *postfix, double x)**

* **Описание:** Вычисляет значение функции для заданного значения x на основе постфиксной записи.
* **Входные данные:** Строка postfix, содержащая постфиксное выражение, и значение x.
* **Выходные данные:** Возвращает значение функции для заданного x.

### Файл postfix.h

* **Описание:** Заголовочный файл, содержащий объявления функций для postfix.c.

### Файл stack.c

#### **void push(Stack *s, double item)**

* **Описание:** Добавляет элемент в стек.
* **Входные данные:** Указатель на структуру Stack и значение item.
* **Выходные данные:** Элемент добавляется в стек.

#### **double pop(Stack *s)**

* **Описание:** Извлекает элемент из стека.
* **Входные данные:** Указатель на структуру Stack.
* **Выходные данные:** Возвращает значение извлеченного элемента.

### Файл stack.h

* **Описание:** Заголовочный файл, содержащий объявления функций и структуры Stack для stack.c.

### Файл Makefile

* **Описание:** Файл для сборки проекта с помощью make. Содержит команды для компиляции, запуска и очистки проекта.

### Файл include_define.h 

* **Описание:** содержит общие включения и определения, которые используются в нескольких модулях проекта. Этот файл включает стандартные библиотеки и определяет некоторые константы, которые используются в проекте.

* **<math.h>:** Для математических функций.
* **<stdio.h>:** Для стандартного ввода/вывода.
* **<stdlib.h>:** Для функций управления памятью и преобразования типов.
* **<string.h>:** Для работы со строками.

* **WIDTH:** Ширина графика в символах (80).
* **HEIGHT:** Высота графика в символах (25).
* **MAX_SIZE:** Максимальный размер стека и других буферов (100).

### Структуры данных

#### **Структура Stack**

* **Описание:** Структура, представляющая стек.
* **Поля:**
  * **double items[MAX_SIZE]:** Массив для хранения элементов стека.
  * **int top:** Индекс вершины стека.

