/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** Does the same thing as the my_strcat but for the n frst bytes of the right
*/

#include <stdlib.h>
#include "my_string.h"

char *my_strncat(const char *left, const char *right, size_t n)
{
    size_t len = my_strlen(left);
    char *new = malloc(len + my_strnlen(right, n) + 1);

    if (!left || !right || !new)
        return (NULL);
    my_strcpy(new, left);
    my_strncpy(&new[len], right, n);
    free((char *) left);
    free((char *) right);
    return (new);
}
