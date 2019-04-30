/*
** EPITECH PROJECT, 2019
** my_linelen.c
** File description:
** Returns the length of a line
*/

#include "my_string.h"

size_t my_linelen(const char *s)
{
    const char *char_ptr = s;

    if (!s)
        return (-1);
    while (*char_ptr && *char_ptr != '\n')
        char_ptr++;
    return (char_ptr - s);
}
