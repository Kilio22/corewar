/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** my_str_ends_with
*/

#include "my_string.h"

int my_str_ends_with(const char *str, const char *end)
{
    size_t len = my_strlen(str);
    size_t endlen = my_strlen(end);

    if (!str || !end)
        return -1;
    if (endlen > len || endlen == 0)
        return (0);
    while (endlen-- > 0) {
        if (str[--len] != end[endlen])
            return (0);
    }
    return (1);
}
