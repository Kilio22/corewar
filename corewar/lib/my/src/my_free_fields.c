/*
** EPITECH PROJECT, 2018
** my_free_fields.c
** File description:
** Frees fields off a char**
*/

#include <stdlib.h>

void my_free_fields(char **array)
{
    char **free_ptr = array;

    if (!array)
        return;
    while (*free_ptr)
        free(*free_ptr++);
    free(array);
}
