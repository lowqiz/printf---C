/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** 5th task
*/

#include <stdlib.h>
#include "../include/my.h"

static int affiche(char *temp, int nbplus, int precision, int min)
{
    int result = 0;

    result += my_putchar(temp[0], 0, 0);
    result += my_putchar('.', 0, 0);
    for (int i = 1; i <= precision; i++){
        if (temp[i] == '.')
            i++;
        result += my_putchar(temp[i], 0, 0);
    }
    result += my_putchar('E' + (32 * min), 0, 0);
    result += my_putchar('+', 0, 0);
    if (nbplus > 9)
        result += my_put_nbr(nbplus, 0, 0);
    else {
        result += my_putchar('0', 0, 0);
        result += my_putchar(nbplus + 48, 0, 0);
    }
    return result;
}

static int affiche_special(double nb, int precision, int min)
{
    char *str;
    int i = 0;
    int result = 0;

    for (; (nb * 10.0) < 1.0; i++)
        nb = nb * 10;
    nb = nb * 10;
    str = double_str(nb, precision);
    result += my_putchar(str[0], 0, 0) + my_putchar('.', 0, 0);
    for (int i = 1; i <= precision; i++){
        if (str[i] == '.')
            i++;
        result += my_putchar(str[i], 0, 0);
    }
    result += my_putchar('E' + (32 * min), 0, 0) + my_putchar('-', 0, 0);
    if (i + 1 > 9)
        result += my_put_nbr(i + 1, 0, 0);
    else
        result += my_putchar('0', 0, 0) + my_putchar(i + 1 + 48, 0, 0);
    return result;
}

int percent_e(double nb, int precision, int min, int specifier)
{
    int nbplus = trouverpuissance((int)nb);
    char *temp;
    int result = 0;

    (void)specifier;
    if (nb < 0.0){
        nb = -nb;
        result += my_putchar('-', 0, 0);
    }
    if (nb < 1.0)
        result += affiche_special(nb, precision, min);
    else {
        temp = double_str(nb, precision);
        result += affiche(temp, nbplus, precision, min);
    }
    return result;
}
