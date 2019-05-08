/*
** EPITECH PROJECT, 2019
** my_fputs.c
** File description:
** Puts the given string on the given file stream
*/

#include <unistd.h>
#include "my_stdio.h"
#include "my_string.h"

size_t my_fputs(const char *s, FILE *fp)
{
    size_t len = my_strlen(s);

    fwrite(s, sizeof(char), len, fp);
    return (len);
}
