/*
** EPITECH PROJECT, 2019
** my_realloc_array.c
** File description:
** Adds one more pointer at the end of an array pointer
*/

#include <stdlib.h>
#include "my_string.h"

char **my_realloc_array(char **array, char *new)
{
    size_t len = my_strarraylen(array);
    char **new_array = malloc(sizeof(char *) * (len + 2));

    if (!new_array || !array)
        return NULL;
    for (size_t i = 0; i < len; i++)
        new_array[i] = array[i];
    new_array[len] = new;
    new_array[len + 1] = NULL;
    free(array);
    return (new_array);
}
