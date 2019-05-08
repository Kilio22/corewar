/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_strcat_nofree
*/

#include <stdlib.h>
#include "my_string.h"

char *my_strcat_nofree(const char *left, const char *right)
{
    size_t len = my_strlen(left);
    char *new = malloc(len + my_strlen(right) + 1);

    if (!left || !right || !new)
        return (NULL);
    my_strcpy(new, left);
    my_strcpy(&new[len], right);
    return (new);
}
