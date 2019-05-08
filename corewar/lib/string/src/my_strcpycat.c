/*
** EPITECH PROJECT, 2019
** my_strcpycat.c
** File description:
** Concatenates a string into another, without malloc
*/

#include "my_string.h"

char *my_strcpycat(char *dest, const char *src)
{
    if (!dest || !src)
        return (NULL);
    dest += my_strlen(dest);
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return (dest);
}
