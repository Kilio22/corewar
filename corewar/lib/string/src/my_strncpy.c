/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** Does the same thing as strcpy but for the first n bytes
*/

#include "my_string.h"

char *my_strncpy(char *dest, const char *src, size_t n)
{
    char *d = dest;
    const char *end_ptr = dest + n;

    if (!dest || !src)
        return (NULL);
    while (*src && dest < end_ptr)
        *dest++ = *src++;
    *dest = '\0';
    return (d);
}
