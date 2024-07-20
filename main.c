#include <stdio.h>
#include <string.h>

// говнокодище
int main() {
    char *name;

    printf("QWEASD: ");
    scanf("%s", name);

    if (strcmp(name, "Сергей") == 0 ) {
        printf("Пошел нахуй черт - %s", name);
    } else {
        printf("Добра пожаловать %s домой!", name);
    }

	return 0;
}
