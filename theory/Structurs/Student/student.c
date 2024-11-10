#include "student.h"

int input_array_students(Student *students, int count_students);
int outpet_name_student_marks(Student *students, int count_students);

int main() {
    int programm = 0;
    int count_students;

    if (scanf("%d", &count_students) != 1 || getchar() != '\n') {
        programm = 1;
    } else {
        Student *students = malloc(count_students * sizeof(Student));

        if (input_array_students(students, count_students)) {
            if (outpet_name_student_marks(students, count_students) == 0) {
                programm = 1;
            }
        } else {
            programm = 1;
        }

        free(students);
    }

    if (programm != 0) {
        printf("n/a");
    }

    return programm;
}

int input_array_students(Student *students, int count_students) {
    int programm = 1;

    for (int i = 0; i < count_students; i++) {
        scanf("%20s", students[i].name);

        if (scanf("%d", &students[i].marks) != 1 || getchar() != '\n') {
            programm = 0;
            break;
        }
    }

    return programm;
}

int outpet_name_student_marks(Student *students, int count_students) {
    int sum_marks = 0;
    int average_value;
    int count_name_student_marks = 0;

    for (int i = 0; i < count_students; i++) {
        sum_marks += students[i].marks;
    }

    average_value = sum_marks / count_students;

    for (int i = 0; i < count_students; i++) {
        if (students[i].marks > average_value) {
            count_name_student_marks++;
        }
    }

    int count = 0;
    for (int i = 0; i < count_students; i++) {
        if (students[i].marks > average_value) {
            printf("%s", students[i].name);

            if (count < count_name_student_marks - 1) {
                printf(", ");
            }

            count++;
        }
    }

    return count_name_student_marks;
}
