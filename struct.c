#include <stdio.h>
#include <string.h>

// Объявление структуры
struct Student
{
    char name[50];
    int age;
    float gpa;
};

// typedef - Для упрощения объявления переменных типа структуры
// Теперь можно использовать в коде как struct Student_typedef, так и просто Student_typedef
typedef struct Student_typedef
{
    char name[50];
    int age;
    float gpa;
} Student_typedef;

// Структуры могут передаваться в функции как аргументы
// Функция, принтующая данные struct Student
void printStudent(struct Student student)
{
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %.2f\n", student.gpa);
}

// Функции могут возвращать структуры
// Функция, заполняющая данные typedef struct Student_typedef
struct Student_typedef createStudent(char name[], int age, float gpa)
{
    Student_typedef student;
    strcpy(student.name, name);
    student.age = age;
    student.gpa = gpa;
    return student;
}

// Структура Циферблат
typedef struct Dial
{
    int hours, minuts, seconds;
} Dial;

// Функция получает минуты и выводит данные в виде циферблата typedef struct Dial
Dial enterTimeMM(int mm)
{
    Dial dial;
    mm %= 1440;
    dial.hours = mm / 60;
    dial.minuts = mm - dial.hours * 60;
    dial.seconds = 0;

    return dial;
}

// Функция, принтующая данные struct Dial
void printTimeDial(Dial dial)
{
    printf("\n ________\n|%02d:%02d:%02d|\n----------\n|________|\n", dial.hours, dial.minuts, dial.seconds);
}

int main()
{
    /* struct Student - экземпляр */
    struct Student student1;
    struct Student student3;

    // Присваивание значений полям структуры
    strcpy(student1.name, "John Doe");
    student1.age = 20;
    student1.gpa = 4.8;

    // Вывод информации о студенте
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n", student1.gpa);

    // Вывод информации о студенте с помощью функции
    printStudent(student1);

    /* typedef struct Student_typedef */
    Student_typedef student2;

    // Присваивание значений полям структуры
    strcpy(student2.name, "John Doe");
    student2.age = 20;
    student2.gpa = 3.8;

    // Вывод информации о студенте
    printf("Name: %s\n", student2.name);
    printf("Age: %d\n", student2.age);
    printf("GPA: %.2f\n", student2.gpa);

    /* typedef struct Student_typedef - массив структур для хранения информации */
    Student_typedef students[3];

    // Присваивание значений полям структур
    strcpy(students[0].name, "John Doe");
    students[0].age = 20;
    students[0].gpa = 3.8;

    strcpy(students[1].name, "Jane Smith");
    students[1].age = 22;
    students[1].gpa = 3.9;

    strcpy(students[2].name, "Bob Johnson");
    students[2].age = 19;
    students[2].gpa = 3.7;

    // Вывод информации о студентах
    for (int i = 0; i < 3; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }

    // Заполнение данными структуры с помощью функции
    Student_typedef student4 = createStudent("John Doe", 20, 3.8);

    // Вывод информации о студенте
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n", student1.gpa);

    // Циферблат
    Dial dial = enterTimeMM(123);
    printTimeDial(dial);

    return 0;
}
