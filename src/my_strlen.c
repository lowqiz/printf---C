/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** 3rd task
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        str++;
        i++;
    }
    return i;
}
