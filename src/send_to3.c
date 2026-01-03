/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my printf project
*/

#include <stdarg.h>
#include "../include/my.h"

int send_to_u(va_list list, int precision, int specifier)
{
    char const *str = "0123456789";

    return my_putnbr_base(va_arg(list, unsigned long long), str, precision,
        specifier);
}

int send_to_x(va_list list, int precision, int specifier)
{
    char const *str = "0123456789abcdef";

    return my_putnbr_base(va_arg(list, unsigned long long), str, precision,
        specifier);
}

int send_to_xmaj(va_list list, int precision, int specifier)
{
    char const *str = "0123456789ABCDEF";

    return my_putnbr_base(va_arg(list, unsigned long long), str, precision,
        specifier);
}

int send_to_o(va_list list, int precision, int specifier)
{
    char const *str = "01234567";

    return my_putnbr_base(va_arg(list, unsigned long long), str, precision,
        specifier);
}

int send_to_b(va_list list, int precision, int specifier)
{
    char const *str = "01";

    return my_putnbr_base(va_arg(list, unsigned long long), str, precision,
        specifier);
}
