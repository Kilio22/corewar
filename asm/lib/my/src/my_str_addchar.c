/*
** EPITECH PROJECT, 2018
** my_str_addchar.c
** File description:
** Adds a char in the given str index
*/

#include <stdlib.h>
#include "my.h"
#include "my_string.h"

char *my_str_addchar(char const *str, char const c, int index)
{
    size_t len = my_strlen(str) + 1;
    char *new_str = malloc(sizeof(char) * (len + 1));

    if (!new_str || !str)
        return NULL;
    my_strncpy(new_str, str, index);
    new_str[index] = c;
    my_strcpy(new_str + index + 1, str  + index);
    free((char *) str);
    return (new_str);
}
