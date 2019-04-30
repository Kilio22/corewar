/*
** EPITECH PROJECT, 2019
** my_remove_ptr_fromarray.c
** File description:
** Takes away a given pointer from the given array
*/

#include <stdlib.h>
#include "my_string.h"

char **my_remove_ptr_fromarray(char **array, char *ptr)
{
    size_t len = my_strarraylen(array);
    char **new_array = malloc(sizeof(char *) * len);
    size_t j = 0;

    if (!new_array || !array)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        if (array[i] == ptr)
            continue;
        new_array[j++] = array[i];
    }
    new_array[len - 1] = NULL;
    free(ptr);
    free(array);
    return (new_array);
}
