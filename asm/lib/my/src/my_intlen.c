/*
** EPITECH PROJECT, 2019
** my_intlen.c
** File description:
** Gets the number of digits in a given integer
*/

int my_intlen(int nb)
{
    int digit_nb = 0;

    do {
        nb /= 10;
        digit_nb++;
    } while (nb);
    return (digit_nb);
}
