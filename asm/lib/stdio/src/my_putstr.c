/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displays the given string on the output terminal
*/

#include <unistd.h>
#include "my_string.h"
#include "my_stdio.h"

size_t my_putstr(const char *s)
{
    size_t len = my_strlen(s);

    write(1, s, len);
    return (len);
}
