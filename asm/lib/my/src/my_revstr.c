/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** Reverses a given string
*/

#include "my.h"
#include "my_string.h"

static int get_remaining_swaps(int len)
{
    if (len % 2 == 0)
        return (len / 2);
    else
        return ((len - 1) / 2);
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int remaining_swaps = get_remaining_swaps(len);
    int right_side = len - 1;
    char swapping_var;

    if (!str)
        return NULL;
    for (int left_side = 0; remaining_swaps > 0; left_side++) {
        swapping_var = str[left_side];
        str[left_side] = str[right_side];
        str[right_side] = swapping_var;
        right_side--;
        remaining_swaps--;
    }
    return (str);
}
