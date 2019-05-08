/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** is_empty
*/

#include "asm.h"

int is_empty_line(const char *line)
{
    if (!line[0])
        return 0;
    while (line) {
        if (!my_strchr((char *) whitespace_chars, *line++))
            return -1;
    }
    return 0;
}
