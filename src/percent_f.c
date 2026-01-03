/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** 5th task
*/

#include <stdlib.h>
#include "../include/my.h"
#include <stdio.h>

int my_round2(double nb, int precision)
{
    double dec = nb - (int)nb;
    int temp = 0;

    for (int i = 0; i <= precision; i++){
        dec = dec * 10;
        temp = temp * 10;
        temp += (int)dec;
        dec = dec - (int)dec;
    }
    return temp;
}

char *detect_0(double nb, int precision)
{
    char *decpart = malloc(sizeof(char) * precision);
    int x = 1;

    for (int y = 0; nb - (int)nb < 0.1 / x; y++){
        if (y < precision - 1)
            decpart[y] = '0';
        x = x * 10;
    }
    return decpart;
}

char *my_round(double nb, int precision, int *intpart)
{
    char *str = malloc(sizeof(char) * precision + 2);
    int temp = my_round2(nb, precision);
    char *decpart = detect_0(nb, precision);

    if (temp % 10 >= 5){
        temp = temp / 10;
        temp++;
    } else
        temp = temp / 10;
    if (temp >= puissance_de_10(precision)){
        *intpart = *intpart + 1;
        return my_strncat(decpart, "00000000000000000000000000", precision);
    }
    if (nb - (int)nb == 0)
        return my_strncat(decpart, "00000000000000000000000000", precision);
    if (temp == 0 && decpart[0] != '0')
        return my_strncat(decpart, "00000000000000000000000000", precision - 1);
    str = int_to_str(temp);
    decpart = my_strncat(decpart, str, precision);
    return decpart;
}

char *double_str(double nb, int precision)
{
    char *str;
    char *intpart;
    char *decpart;
    int intnb = nb;

    decpart = my_round(nb, precision, &intnb);
    intpart = int_to_str(intnb);
    intpart = my_strncat(intpart, "..", 1);
    str = my_strcat(intpart, decpart);
    return str;
}

int print_double(double nb, int precision, int specifier)
{
    int result = 0;
    char *str;

    if (nb < 0.0){
        nb = -nb;
        result += my_putchar('-', 0, 0);
    }
    (void)specifier;
    str = double_str(nb, precision);
    result += my_putstr(str, 0, 0);
    return result;
}
