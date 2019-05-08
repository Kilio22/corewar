/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** quote_len
*/

#include "asm.h"

size_t my_quote_len(char *line)
{
    size_t i = 0;

    for (; line[i] && line[i] != '"'; i++);
    return i - 1;
}