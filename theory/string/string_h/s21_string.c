#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char *str);
int s21_strcmp(const char *str_one, const char *str_two);
int s21_strcpy(char *str_one, const char *str_two);
int s21_strcat(char *str_one, const char *str_two);
int s21_strchr(const char *str, char c);

int s21_strlen(const char *str) {
    int lenstr = 0;

    for (; *(str + lenstr); lenstr++)
        ;

    return lenstr;
}

int s21_strcmp(const char *str_one, const char *str_two) {
    int programm = 0;

    if (s21_strlen(str_one) != s21_strlen(str_two)) {
        programm = -1;
    } else {
        for (int i = 0; i < s21_strlen(str_one); i++) {
            if (str_one[i] != str_two[i]) {
                programm = 1;
                break;
            }
        }
    }

    return programm;
}

int s21_strcpy(char *str_one, const char *str_two) {
    int programm = 0;

    if (s21_strlen(str_one) > s21_strlen(str_two)) {
        programm = -1;
    } else {
        int i = 0;
        while (str_two[i] != '\0') {
            str_one[i] = str_two[i];
            i++;
        }

        str_one[i] = '\0';
    }

    return programm;
}

int s21_strcat(char *str_one, const char *str_two) {
    int programm = 0;

    int str_one_len = s21_strlen(str_one);
    int i = 0;

    while (str_two[i] != '\0') {
        str_one[str_one_len + i] = str_two[i];
        i++;
    }

    str_one[str_one_len + i] = '\0';

    return programm;
}

int s21_strchr(const char *str, char c) {
    int result = -1;
    int count = 0;

    while (str[count] != '\0') {
        if (str[count] == c) {
            result = count;
            break;
        }

        count++;
    }

    return result;
}
