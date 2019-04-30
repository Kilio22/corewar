/*
** EPITECH PROJECT, 2019
** my_itoa.c
** File description:
** Makes an int becore a char *
*/

#include "my.h"
#include "my_string.h"

char *my_itoa(int nb)
{
    char str[50] = {0};
    int isneg = (nb < 0) ? 1 : 0;
    int r;
    int i = 0;

    if (nb == -2147483648)
        return (my_strdup("-2147483648"));
    nb = (nb < 0) ? -nb : nb;
    do {
        r = nb % 10;
        nb /= 10;
        str[i++] = r + '0';
    } while (nb);
    if (isneg)
        str[i++] = '-';
    str[i] = '\0';
    return (my_strdup(my_revstr(str)));
}
