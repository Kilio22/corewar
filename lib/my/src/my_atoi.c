/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** Takes an int out of a char *
*/

#include "my_string.h"

int my_atoi(char const *str)
{
    int length = my_strlen(str);
    long long int result = 0;
    int is_negative = 0;
    int i;

    for (i = 0; str[i] < '0' || str[i] > '9'; i++) {
        if ((str[i] - '-') == 0)
            is_negative++;
        if (str[i] != '-' && str[i] != '+')
            return (0);
    }
    for (; i < length && (str[i] >= '0' && str[i] <= '9'); i++) {
        result = result * 10 + (str[i] - '0');
        if (result < -2147483648 || result > 2147483647)
            return (0);
    }
    return (is_negative ? -result : result);
}
