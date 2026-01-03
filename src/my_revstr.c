/*
** EPITECH PROJECT, 2025
** my_evil_str
** File description:
** 4th task
*/

#include "../include/my.h"

static void swap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char * my_revstr(char *str)
{
    int i = my_strlen(str);
    int c1 = 0;
    char *point1;
    char *point2;
    int t = i / 2;

    while (t != 0){
        point1 = &str[c1];
        point2 = &str[i - 1];
        swap(point1, point2);
        c1++;
        i--;
        t--;
    }
    return str;
}
