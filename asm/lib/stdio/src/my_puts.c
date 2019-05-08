/*
** EPITECH PROJECT, 2019
** my_puts.c
** File description:
** Writes a given string and a trailing newline to stdout.
*/

#include <unistd.h>
#include "my_string.h"
#include "my_stdio.h"

size_t my_puts(const char *s)
{
    my_putstr(s);
    my_putchar('\n');
    return (my_strlen(s) + 1);
}
