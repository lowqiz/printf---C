/*
** EPITECH PROJECT, 2025
** percent p
** File description:
** percent p
*/

#include "../include/my.h"
#include <stdio.h>

double percent_g2(double nb, int *nega, int *cpt_exposant)
{
    if (nb < 0) {
        *nega = *nega + 1;
        nb = -nb;
    }
    if (nb >= 10){
        while (nb >= 10) {
            nb = nb / 10;
            *cpt_exposant = *cpt_exposant + 1;
        }
    }
    return nb;
}

int percent_g(double nb, int precision, int min, int specifier)
{
    int result = 0;
    double tmp = nb;
    int cpt_exposant = 0;
    int nega = 0;

    (void)specifier;
    nb = percent_g2(nb, &nega, &cpt_exposant);
    if (nb < 1 && nb != 0){
        for (; nb < 1; cpt_exposant--)
            nb = nb * 10;
    }
    if (nega)
        result += my_putchar('-', 0, 0);
    if (cpt_exposant < -4 || cpt_exposant >= precision){
        result += percent_e(tmp, precision, min, 0);
    } else
        result += print_double(tmp, precision, 0);
    return result;
}
