/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my printf project
*/

#include <stdarg.h>
#include "../include/my.h"

int send_to_e(va_list list, int precision, int specifier)
{
    if (precision == 0)
        precision = 6;
    return percent_e(va_arg(list, double), precision, 1, specifier);
}

int send_to_eup(va_list list, int precision, int specifier)
{
    if (precision == 0)
        precision = 6;
    return percent_e(va_arg(list, double), precision, 0, specifier);
}

int send_to_f(va_list list, int precision, int specifier)
{
    if (precision == 0)
        precision = 6;
    return print_double(va_arg(list, double), precision, specifier);
}

int send_to_g(va_list list, int precision, int specifier)
{
    if (precision == 0)
        precision = 6;
    return percent_g(va_arg(list, double), precision, 1, specifier);
}

int send_to_gup(va_list list, int precision, int specifier)
{
    if (precision == 0)
        precision = 6;
    return percent_g(va_arg(list, double), precision, 0, specifier);
}
