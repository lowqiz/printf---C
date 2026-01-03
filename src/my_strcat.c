/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** 5th task
*/

#include "../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);

    for (int j = 0; src[j] != '\0'; j++){
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
