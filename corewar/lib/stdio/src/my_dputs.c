/*
** EPITECH PROJECT, 2019
** my_dputs.c
** File description:
** Puts the given string on the given file descriptior
*/

#include <unistd.h>
#include "my_stdio.h"
#include "my_string.h"

size_t my_dputs(const char *s, int fd)
{
    size_t len = my_strlen(s);

    write(fd, s, len);
    return (len);
}
