/*
** EPITECH PROJECT, 2019
** my_stralloc.c
** File description:
** Allocates a char * and fills it with the given character
*/

#include <stdlib.h>
#include "my_string.h"

char *my_stralloc(size_t size, char c)
{
    char *str = malloc(sizeof(char) * (size + 1));

    if (!str)
        return (NULL);
    my_memset((void *) str, c, size);
    str[size] = '\0';
    return (str);
}
