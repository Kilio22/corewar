/*
** EPITECH PROJECT, 2018
** my_arraylen.c
** File description:
** Returns the length of a char ** (or void **)
*/

#include "my_string.h"

size_t my_arraylen(void **array)
{
    void **ptr = array;

    if (!ptr)
        return (-1);
    while (*ptr)
        ptr++;
    return (ptr - array);
}

size_t my_strarraylen(char **array)
{
    char **ptr = array;

    if (!ptr)
        return (-1);
    while (*ptr)
        ptr++;
    return (ptr - array);
}
