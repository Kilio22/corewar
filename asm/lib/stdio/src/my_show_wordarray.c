/*
** EPITECH PROJECT, 2019
** my_show_word_array.c
** File description:
** Prints the given array of strings
*/

#include "my_stdio.h"

void my_show_wordarray(char **array)
{
    while (*array)
        my_puts(*array++);
}
