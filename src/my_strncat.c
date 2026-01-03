/*
** EPITECH PROJECT, 2025
** my_evil_str
** File description:
** 4th task
*/

#include "../include/my.h"

char * my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);

    for (int j = 0; (src[j] != '\0'); j++){
        dest[i] = src[j];
        i++;
        if (nb - 1 == j){
            dest[i] = '\0';
            return dest;
        }
    }
    dest[i] = '\0';
    return dest;
}
