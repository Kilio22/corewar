/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** delete_end_whitespaces
*/

#include "asm.h"

char *delete_end_whitespaces(char *line)
{
    size_t i = my_strlen(line) - 1;

    for (; i > 0; i--) {
        if (!my_strchr((char *) whitespace_chars, line[i]))
            return line;
        line[i] = '\0';
    }
    return line;
}
