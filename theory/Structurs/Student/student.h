#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 21

typedef struct {
    char name[MAX_NAME];
    int marks;
} Student;

#endif
