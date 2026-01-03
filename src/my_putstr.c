/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** 2rd task
*/

#include "../include/my.h"
#include <stdio.h>

int my_putstr(char const *str, int precision, int specifier)
{
    int total = 0;

    (void)specifier;
    if (precision == 0)
        precision = my_strlen(str);
    while (*str != '\0' && precision != 0){
        my_putchar(*str, 0, 0);
        total++;
        str++;
        precision--;
    }
    return total;
}
