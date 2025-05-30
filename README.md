# Theoretical material on C++ and C
<a name="up"></a>

---

## Working with the GCC compiler and other utilities

### Compiling code using the **gcc** compiler

#### [name] - the name of the compiled one .exe file (main.exe, main.out ...)

```commandline
gcc main.c -o [name]
```

#### Automatic file name (a.exe, a.out ...)

```commandline
gcc main.c
```

### Show additional warnings from the gcc compiler

#### **-Wall -Wextra -Werror** - flags that include warnings to improve code quality and detect potential problems

```commandline
gcc -std=c11 -Wall -Wextra -Werror -pedantic main.c
```

### Running compiled code

#### [name] - the name of the compiled one .exe file (main.exe, main.out ...)

```commandline
./[name]
```

### Static code analysis **cppcheck** ➜ detect potential errors and problems in the code

#### [name] - the name of the compiled file (main.c ...)

```commandline
cppcheck --enable=all --suppress=missingIncludeSystem [name]
```

### Checking for memory leaks **leaks** compiled file on **Mac OS**

#### [name] - the name of the compiled file (main.out ...)

```commandline
MallocStackLogging=1 leaks -q -atExit -- ./[name]
```

### Checking for memory leaks **valgrind** compiled file on **Linux**

#### [name] - the name of the compiled file (main.out ...)

```commandline
valgrind --tool=memcheck --leak-check=yes ./[name]
```

---

### Formatting C code in Visual Studio Code

#### Install the extension [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) or [Clang-Format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format) in Visual Studio Code

#### **Windows/Linux**: Press **CTRL + SHIFT + P** ➜ enter **Format Document** ➜ select **C/C++ Clang-Format** or press **ALT + SHIFT + F**

#### **Mac Os**: Press **SHIFT + COMMAND + P** ➜ enter **Format Document** ➜ select **C/C++ Clang-Format** or press **SHIFT + OPTION + F**

>For [Clang-Format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format), you need to install ```clang-format``` itself into the operating system

#### **Windows**

```commandline
choco install llvm
```

#### **Mac Os**

```commandline
brew install clang-format
```

#### **Arch Linux**

```commandline
sudo pacman -S clang
```

>After installing ```Clang-Format```, the basic commands for working with the code format are

#### Checking the code style

```commandline
clang-format -n main.c
```

#### Auto-formatting the code style

```commandline
clang-format -i main.c
```

---

### A good course on the C programming language from MIPT teachers (Taught in the 1st year of MIPT) on [Stepik](https://stepik.org/course/57680/info)

---

#### [README](README.md) [UP](#up)

---

# Теоритический материал по C++ и C

<a name="вверх"></a>

---

## Работа с компилятором GCC и другими утилитами

### Компилирование кода с помощью компилятора **gcc**

#### [name] - название скомпилированного файла (main.exe, main.out ...)

```commandline
gcc main.c -o [name]
```

#### Автоматическое название файла (a.exe, a.out ...)

```commandline
gcc main.c
```

### Показать дополнительные предупреждения от компилятора gcc

#### **-Wall -Wextra -Werror** - флаги, включающие предупреждения для повышения качества кода и обнаружения потенциальных проблем

```commandline
gcc gcc -std=c11 -Wall -Wextra -Werror -pedantic main.c
```

### Запуск скомпилированного кода

#### [name for] - название скомпилированного файла (main.exe, main.out ...)

```commandline
./[name]
```

### Статический анализ кода **cppcheck** ➜ обнаружить потенциальные ошибки и проблемы в коде

#### [name] - название скомпилированного файла (main.c ...)

```commandline
cppcheck --enable=all --suppress=missingIncludeSystem [name]
```

### Проверка утечки памяти **leaks** скомпилированного файла на **Mac OS**

#### [name] - название скомпилированного файла (main.out ...)

```commandline
MallocStackLogging=1 leaks -q -atExit -- ./[name]
```

### Проверка утечки памяти **valgrind** скомпилированного файла на **Linux**

#### [name] - название скомпилированного файла (main.out ...)

```commandline
valgrind --tool=memcheck --leak-check=yes ./[name]
```

---

### Форматирование кода на C в Visual Studio Code

#### Установить расширение [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) или [Clang-Format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format) в Visual Studio Code

#### **Windows/Linux**: Нажать комбинацию клавиш **CTRL + SHIFT + P** ➜ ввести **Format Document** ➜ выбрать**C/C++ Clang-Format** или нажать комбинацию клавиш**ALT + SHIFT + F**

#### **Mac OS**: Нажать комбинацию клавиш **SHIFT + COMMAND + P** ➜ ввести **Format Document** ➜ выбрать **C/C++ Clang-Format** или нажать комбинацию клавиш**SHIFT + OPTION + F**

>Для [Clang-Format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format) необходимо установить сам ```clang-format``` в операционную систему

#### **Windows**

```commandline
choco install llvm
```

#### **Mac Os**

```commandline
brew install clang-format
```

#### **Arch Linux**

```commandline
sudo pacman -S clang
```

>После установки ```Clang-Format``` основные команды для работы с форматом кода

#### Проверка стиля кода

```commandline
clang-format -n main.c
```

#### Автоформати́рование стиля кода

```commandline
clang-format -i main.c
```

---

### Хороший крус по языку программирования C от преподавателей МФТИ (Читается на 1 курсе МФТИ) на [Stepik](https://stepik.org/course/57680/info)

---

#### [README](README.md) [ВВЕРХ](#вверх)

---

## Полезные расширения для **Visual Studio Code**

### Основные расширения

1. [**C/C++**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) - Основное расширение для работы с C и C++ в VSCode
2. [**C/C++ Runner**](https://marketplace.visualstudio.com/items?itemName=franneck94.c-cpp-runner) - Упрощает запуск и отладку проектов на C и C++
3. [**CMake Tools**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) - Инструменты для работы с CMake в VSCode

### Инструменты форматирования и анализа кода

1. [**C/C++**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) - Основное расширение для работы с C и C++ в VSCode
2. [**CodeLLDB**](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) - Отладчик для C, C++, Rust и других языков, использующих LLVM
3. [**Clang-Format**](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format) - Инструмент форматирования кода для C, C++, Objective-C, Java, JavaScript и TypeScript

### Визуальные улучшения

1. [**Midnight Codium**](https://marketplace.visualstudio.com/items?itemName=mischah.midnight-codium) - Темная тема для VSCode с улучшенной контрастностью
2. [**Atom Material Icons**](https://marketplace.visualstudio.com/items?itemName=donjayamanne.python-environment-manager) - Красивые иконки для файлов и папок в стиле Material Design
3. [**Better C++ Syntax**](https://marketplace.visualstudio.com/items?itemName=jeff-hykin.better-cpp-syntax) - Улучшенная подсветка синтаксиса для C и C++

### Инструменты разработки

1. [**Russian Language Pack for Visual Studio Code**](https://marketplace.visualstudio.com/items?itemName=MS-CEINTL.vscode-language-pack-ru) - Локализация VSCode на русский язык
2. [**GitLens**](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens) - Расширенная поддержка Git в VSCode
3. [**Live Server**](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer) - Локальный запуск и просмотр изменений в реальном времени (полезно для разработки веб-приложений на C с использованием WebAssembly)
