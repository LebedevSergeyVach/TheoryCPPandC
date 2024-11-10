#ifndef S21_STRING_H
#define S21_STRING_H

#define MAXDYNAMICARRAY 15
#define OPERATINGMODE 3

int s21_strlen(const char *str);
int s21_strcmp(const char *str_one, const char *str_two);
int s21_strcpy(char *str_one, const char *str_two);
int s21_strcat(char *str_one, const char *str_two);
int s21_strchr(const char *str, char c);

#endif
