#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 100

typedef struct
{
    char a[N];      // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n; // наибольшая степень десяти
} Decimal;

void elong_set(Decimal *res, const char str[])
{
    int len = strlen(str);
    if (len > N)
    {
        len = N; // Убедитесь, что мы не превышаем размер массива
    }

    // Инициализируйте массив равным нулю
    for (int i = 0; i < N; i++)
    {
        res->a[i] = 0;
    }

    // Скопируйте цифры из строки в массив
    for (int i = 0; i < len; i++)
    {
        if (isdigit(str[i]))
        {
            res->a[len - 1 - i] = str[i] - '0';
        }
        else
        {
            // Недопустимый символ в строке
            res->a[len - 1 - i] = 0;
        }
    }

    res->n = len - 1; // Установите наивысшую степень из десяти
}

void elong_print(Decimal decimal)
{
    printf("%d", decimal);
}

int main()
{
    Decimal res;
    elong_set(&res, "12345678901234567890"); // res = 12345678901234567890

    elong_print(res); // print 12345678901234567890

    return 0;
}
