#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen_test(const char *str, int operating_mode);
int s21_strcmp_test(const char *str_one, const char *str_two, int operating_mode);
int s21_strcpy_test(char *str_one, const char *str_two, int operating_mode);
int s21_strcat_test(char *str_one, const char *str_two, int operating_mode);
int s21_strchr_test(const char *str, int operating_mode);

int main() {
#ifdef TEST_STRLEN
    char *str_test_s21_strlen = malloc(MAXDYNAMICARRAY * sizeof(char));

    printf("Start test func s21_strlen:\n\t");
    for (int i = 0; i < OPERATINGMODE; i++) {
        int test = s21_strlen_test(str_test_s21_strlen, i);
        if (test != 0) {
            printf("FAIL");
        } else {
            printf("SUCCESS");
        }
        if (i < OPERATINGMODE - 1) {
            printf("\n\t");
        }
    }
    printf("\n");

    free(str_test_s21_strlen);
#endif

#ifdef TEST_STRCMP
    char *str_test_s21_strcmp_one = malloc(MAXDYNAMICARRAY * sizeof(char));
    char *str_test_s21_strcmp_two = malloc(MAXDYNAMICARRAY * sizeof(char));

    printf("Start test func s21_strcmp:\n\t");
    for (int i = 0; i < OPERATINGMODE; i++) {
        int test = s21_strcmp_test(str_test_s21_strcmp_one, str_test_s21_strcmp_two, i);
        if (test != 0) {
            printf("FAIL");
        } else {
            printf("SUCCESS");
        }
        if (i < OPERATINGMODE - 1) {
            printf("\n\t");
        }
    }
    printf("\n");

    free(str_test_s21_strcmp_one);
    free(str_test_s21_strcmp_two);
#endif

#ifdef TEST_STRCPY
    char *str_test_s21_strcpy_one = malloc(MAXDYNAMICARRAY * sizeof(char));
    char *str_test_s21_strcpy_two = malloc(MAXDYNAMICARRAY * sizeof(char));

    printf("Start test func s21_strcpy:\n\t");
    for (int i = 0; i < OPERATINGMODE; i++) {
        str_test_s21_strcpy_one[0] = '\0';
        int test = s21_strcpy_test(str_test_s21_strcpy_one, str_test_s21_strcpy_two, i);
        if (test != 0) {
            printf("FAIL");
        } else {
            printf("SUCCESS");
        }
        if (i < OPERATINGMODE - 1) {
            printf("\n\t");
        }
    }
    printf("\n");

    free(str_test_s21_strcpy_one);
    free(str_test_s21_strcpy_two);
#endif

#ifdef TEST_STRCAT
    char *str_test_s21_strcat_one = malloc(MAXDYNAMICARRAY * sizeof(char));
    char *str_test_s21_strcat_two = malloc(MAXDYNAMICARRAY * sizeof(char));

    printf("Start test func s21_strcat:\n\t");
    for (int i = 0; i < OPERATINGMODE; i++) {
        str_test_s21_strcat_one[0] = '\0';
        int test = s21_strcat_test(str_test_s21_strcat_one, str_test_s21_strcat_two, i);
        if (test != 0) {
            printf("FAIL");
        } else {
            printf("SUCCESS");
        }
        if (i < OPERATINGMODE - 1) {
            printf("\n\t");
        }
    }
    printf("\n");

    free(str_test_s21_strcat_one);
    free(str_test_s21_strcat_two);
#endif

#ifdef TEST_STRCHR
    char *str_test_s21_strchr = malloc(MAXDYNAMICARRAY * sizeof(char));

    printf("Start test func s21_strchr:\n\t");
    for (int i = 0; i < OPERATINGMODE; i++) {
        int test = s21_strchr_test(str_test_s21_strchr, i);
        if (test != 0) {
            printf("FAIL");
        } else {
            printf("SUCCESS");
        }
        if (i < OPERATINGMODE - 1) {
            printf("\n\t");
        }
    }
    printf("\n");

    free(str_test_s21_strchr);
#endif

    return 0;
}

int s21_strlen_test(const char *str, int operating_mode) {
    int len, programm = 0;

    if (operating_mode == 0) {
        str = "Hello, World!";
        len = 13;
        printf("%d) %s %d %d - ", operating_mode + 1, str, len, s21_strlen(str));
    } else if (operating_mode == 1) {
        str = "Hello, 0 World!";
        len = 15;
        printf("%d) %s %d %d - ", operating_mode + 1, str, len, s21_strlen(str));
    } else if (operating_mode == 2) {
        str = "Hello, \0 World!";
        len = 7;
        printf("%d) %s %d %d - ", operating_mode + 1, str, len, s21_strlen(str));
    } else {
        str = "\n";
        len = 1;
    }

    if (s21_strlen(str) != len) {
        programm = 1;
    }

    return programm;
}

int s21_strcmp_test(const char *str_one, const char *str_two, int operating_mode) {
    int prog, programm = 0;

    if (operating_mode == 0) {
        str_one = "Hello, World!";
        str_two = "Hello, World!";
        prog = 0;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcmp(str_one, str_two));
    } else if (operating_mode == 1) {
        str_one = "Hello, World!";
        str_two = "Привет, Мир!";
        prog = -1;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcmp(str_one, str_two));
    } else if (operating_mode == 2) {
        str_one = "Hello\0qweasd";
        str_two = "Hallo";
        prog = 1;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcmp(str_one, str_two));
    } else {
        str_one = "\0qweasd";
        str_two = "";
        prog = 0;
    }

    if (s21_strcmp(str_one, str_two) != prog) {
        programm = 1;
    }

    return programm;
}

int s21_strcpy_test(char *str_one, const char *str_two, int operating_mode) {
    int prog, programm = 0;

    if (operating_mode == 0) {
        str_two = "Hello, World!";
        prog = 0;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcpy(str_one, str_two));
    } else if (operating_mode == 1) {
        str_two = "";
        prog = 0;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcpy(str_one, str_two));
    } else if (operating_mode == 2) {
        str_two = "Test with null\0character";
        prog = 0;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcpy(str_one, str_two));
    } else {
        str_two = "Hello, World!";
        prog = 0;
    }

    if (s21_strcpy(str_one, str_two) != prog) {
        programm = 1;
    }

    return programm;
}

int s21_strcat_test(char *str_one, const char *str_two, int operating_mode) {
    int prog, programm = 0;

    if (operating_mode == 0) {
        str_two = "Hello, World!";
        prog = 0;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcat(str_one, str_two));
    } else if (operating_mode == 1) {
        str_two = "";
        prog = 0;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcat(str_one, str_two));
    } else if (operating_mode == 2) {
        str_two = "Test\0";
        prog = 0;
        printf("%d) %s %s %d %d - ", operating_mode + 1, str_one, str_two, prog,
               s21_strcat(str_one, str_two));
    } else {
        str_two = "Hello, World!";
        prog = 0;
    }

    if (s21_strcat(str_one, str_two) != prog) {
        programm = 1;
    }

    return programm;
}

int s21_strchr_test(const char *str, int operating_mode) {
    int prog, programm = 0;
    char ch;

    if (operating_mode == 0) {
        str = "Hello, World!";
        ch = 'W';
        prog = 7;
        printf("%d) %s %c %d %d - ", operating_mode + 1, str, ch, prog, s21_strchr(str, ch));
    } else if (operating_mode == 1) {
        str = "Hello, World!";
        ch = 'e';
        prog = 1;
        printf("%d) %s %c %d %d - ", operating_mode + 1, str, ch, prog, s21_strchr(str, ch));
    } else if (operating_mode == 2) {
        str = "Hello, World!";
        ch = 'q';
        prog = -1;
        printf("%d) %s %c %d %d - ", operating_mode + 1, str, ch, prog, s21_strchr(str, ch));
    } else {
        str = "Hello, World!";
        ch = 'H';
        prog = 0;
    }

    if (s21_strchr(str, ch) != prog) {
        programm = 1;
    }

    return programm;
}
