/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** 5th task
*/

#include "../include/my.h"
#include <stdlib.h>


int puissance_de_10(int a)
{
    int i;
    int b;

    b = 1;
    for (i = a; i > 0; i--){
        b = b * 10;
    }
    return b;
}

int trouverpuissance(int nb)
{
    int compt;
    int puissance;

    if (nb < 0)
        nb = -nb;
    compt = 0;
    puissance = 1;
    while (nb >= 10 * puissance){
        puissance = puissance * 10;
        compt++;
    }
    return compt;
}

static int isneg(int x)
{
    if (x >= 0){
        return x;
    } else {
        x = -x;
        return x;
    }
}

char *int_to_str(int x)
{
    int compteur = trouverpuissance(x);
    char *result = malloc(sizeof(char) * (compteur + 1));
    int i = 0;

    if (compteur < 6)
        result = malloc(sizeof(char) * 10);
    if (x != isneg(x)){
        result[i] = '-';
        i++;
        x = -x;
    }
    for (; compteur >= 0; compteur--){
        result[i] = (x / (puissance_de_10(compteur)) + 48);
        x = x - puissance_de_10(compteur) * (x / puissance_de_10(compteur));
        i++;
    }
    result[i] = '\0';
    return result;
}
