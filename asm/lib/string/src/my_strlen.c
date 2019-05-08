/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** Returns the length of a given string pointer
*/

#include "my_string.h"

size_t my_strlen(const char *s)
{
    const char *char_ptr = s;

    if (!s)
        return (-1);
    while (*char_ptr)
        char_ptr++;
    return (char_ptr - s);
}
