/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** delete_spaces
*/

#include "asm.h"

char *skip_whitespaces(char *line)
{
    while (line)
        if (!my_strchr((char *) whitespace_chars, *line++)) {
            line--;
            return line;
        }
    return line;
}
