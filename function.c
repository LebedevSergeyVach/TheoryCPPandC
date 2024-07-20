#include <stdio.h>

int main() {
    greet("Alice");
    greet("Bob");

    return 0;
}

// Функция
void greet(char name[]) {
    printf("Hello, %s!\n", name);
}
