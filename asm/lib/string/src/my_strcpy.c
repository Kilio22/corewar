/*
** EPITECH PROJECT, 2019
** MY_STRCPY.C
** File description:
** Fills a given string with the content of another
*/

#include "my_string.h"

char *my_strcpy(char *dest, const char *src)
{
    char *d = dest;

    if (!dest || !src)
        return (NULL);
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return (d);
}
