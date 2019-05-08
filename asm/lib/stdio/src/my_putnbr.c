/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Prints an int
*/

#include "my_stdio.h"

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb / 10)
        my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return (0);
}
