/*
** EPITECH PROJECT, 2025
** percent p
** File description:
** percent p
*/

#include "../include/my.h"

int percent_p(void *ptr, int precision, int specifier)
{
    (void)precision;
    (void)specifier;
    my_putchar('0', 0, 0);
    my_putchar('x', 0, 0);
    return my_putnbr_base((unsigned long long)ptr, "0123456789abcdef", 0, 0);
}
