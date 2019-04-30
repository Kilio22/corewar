/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** Returns 1 if the whole given string is only numbers
*/

#include "my.h"
#include "my_string.h"

int my_str_isnum(char const *str, int neg)
{
    if (!str)
        return 0;
    if (neg && *str == '-' && my_strlen(str) > 1)
        str++;
    while (*str) {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}
