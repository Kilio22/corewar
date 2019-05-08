/*
** EPITECH PROJECT, 2018
** my_arraylen.c
** File description:
** Returns the length of a char ** (or void **)
*/

#include "my_string.h"

size_t my_arraynlen(void **array, size_t maxlen)
{
    void **ptr = array;
    void **end_ptr = array + maxlen;

    if (!ptr)
        return (-1);
    while (*ptr && ptr < end_ptr)
        ptr++;
    return (ptr - array);
}

size_t my_strarraynlen(char **array, size_t maxlen)
{
    char **ptr = array;
    char **end_ptr = array + maxlen;

    if (!ptr)
        return (-1);
    while (*ptr && ptr < end_ptr)
        ptr++;
    return (ptr - array);
}
