/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** Allocates a memory zone the copies the string pointer's content in it
*/

#include <stdlib.h>
#include "my_string.h"

char *my_strdup(const char *s)
{
    size_t len = my_strlen(s) + 1;
    char *new = malloc(len);

    if (!s || !new)
        return (NULL);
    my_strcpy(new, s);
    return (new);
}
