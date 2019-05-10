/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** cut_strings
*/

#include "asm.h"

char *slice_string(char **src, size_t index)
{
    char *new = malloc(sizeof(char) * (index + 1));
    size_t i = 0;

    if (!new)
        return NULL;
    for (; (*src)[i] && i < index; i++)
        new[i] = (*src)[i];
    new[i] = '\0';
    for (i = 0; *src && i <= index; i++)
        (*src)++;
    return new;
}

char *cut_string(char **src, size_t index)
{
    char *new = malloc(sizeof(char) * (index + 1));
    size_t i = 0;

    if (!new)
        return NULL;
    for (; (*src)[i] && i < index; i++)
        new[i] = (*src)[i];
    new[i] = '\0';
    for (i = 0; *src && i < index; i++)
        (*src)++;
    return new;
}