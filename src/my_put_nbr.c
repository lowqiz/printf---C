/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** 7th project
*/

#include "../include/my.h"

static long long isneg(long long x)
{
    if (x >= 0){
        return x;
    } else {
        my_putchar('-', 0, 0);
        x = -x;
        return x;
    }
}

static long long puissance_de_101(long long a)
{
    long i;
    long b;

    b = 1;
    for (i = a - 1; i > 0; i--){
        b = b * 10;
    }
    return b;
}

static long long trouverpuissance1(long long nb)
{
    long compt;
    long puissance;

    compt = 0;
    puissance = 1;
    while (nb >= 10 * puissance){
        puissance = puissance * 10;
        compt++;
    }
    return compt;
}

int my_put_nbr(long long nb, int precision, int specifier)
{
    int x = trouverpuissance1(nb);
    int a;
    long long b;
    int total = 0;

    (void)specifier;
    for (; precision - x > 1; x++){
        my_putchar('0', 0, 0);
        total++;
    }
    total += (nb < 0);
    nb = isneg(nb);
    for (x = trouverpuissance1(nb) + 1; x > 0; x--){
        b = puissance_de_101(x);
        a = nb / b;
        my_putchar(a + 48, 0, 0);
        total++;
        nb -= b * a;
    }
    return total;
}
