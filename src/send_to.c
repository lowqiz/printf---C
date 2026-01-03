/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my printf project
*/

#include <stdarg.h>
#include "../include/my.h"

int send_to_str(va_list list, int precision, int specifier)
{
    return my_putstr(va_arg(list, char*), precision, specifier);
}

int send_to_putchar(va_list list, int precision, int specifier)
{
    return my_putchar(va_arg(list, int), precision, specifier);
}

int send_to_putnbr(va_list list, int precision, int specifier)
{
    long long value = (va_arg(list, long long));

    if (specifier == 1)
        value = (long)value;
    if (specifier == 4)
        value = (short)value;
    if (specifier == 5)
        value = (unsigned char)value;
    if (specifier == 0)
        value = (int)value;
    return my_put_nbr(value, precision, specifier);
}

int send_to_putnbr_base(va_list list, int precision, int specifier)
{
    long long value = (va_arg(list, long long));

    if (specifier == 1)
        value = (long)value;
    if (specifier == 4)
        value = (short)value;
    if (specifier == 5)
        value = (unsigned char)value;
    if (specifier == 0)
        value = (int)value;
    if (specifier == 6)
        value = (long long)value;
    return my_put_nbr(value, precision, specifier);
}

int send_to_percent_p(va_list list, int precision, int specifier)
{
    return percent_p(va_arg(list, int *), precision, specifier);
}
