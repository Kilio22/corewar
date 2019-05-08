/*
** EPITECH PROJECT, 2019
** my_dputc.c
** File description:
** Puts the given char on the given file descriptior
*/

#include <unistd.h>
#include "my_stdio.h"

int my_dputc(int c, int fd)
{
    write(fd, &c, 1);
    return (1);
}
