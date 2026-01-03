/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** 5th task
*/

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
