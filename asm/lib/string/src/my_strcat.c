/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** Concatenates two given strings (allocates the new one, frees the others)
*/

#include <stdlib.h>
#include "my_string.h"

char *my_strcat(const char *left, const char *right)
{
    size_t len = my_strlen(left);
    char *new = malloc(len + my_strlen(right) + 1);

    if (!left || !right || !new)
        return (NULL);
    my_strcpy(new, left);
    my_strcpy(&new[len], right);
    free((char *) left);
    free((char *) right);
    return (new);
}
