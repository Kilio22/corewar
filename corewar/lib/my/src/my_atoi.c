/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** Takes an int out of a char *
*/

#include "my.h"
#include "my_string.h"

int my_atoi(char const *str)
{
    int res = 0;
    int is_neg = 0;

    if (!my_str_isnum(str, 1))
        return 0;
    if (*str == '-') {
        is_neg = 1;
        str++;
    }
    for (size_t i = 0; str[i]; i++) {
        res *= 10;
        res += str[i] - '0';
    }
    return is_neg ? -res : res;
}
