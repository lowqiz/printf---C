/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** 5th task
*/

#include <unistd.h>

int my_putchar(char c, int precision, int specifier)
{
    (void)precision;
    (void)specifier;
    return write(1, &c, 1);
}
