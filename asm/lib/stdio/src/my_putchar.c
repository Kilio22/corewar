/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** Displays the given char on the output terminal
*/

#include <unistd.h>
#include "my_stdio.h"

int my_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}
