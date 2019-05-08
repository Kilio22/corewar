/*
** EPITECH PROJECT, 2019
** my_fputc.c
** File description:
** Puts the given char on the given file stream
*/

#include <unistd.h>
#include "my_stdio.h"

int my_fputc(int c, FILE *fp)
{
    fwrite(&c, sizeof(char), 1, fp);
    return (1);
}
