/*
** EPITECH PROJECT, 2019
** free_em.c
** File description:
** Frees all the given arguments
*/

#include <stdarg.h>
#include <stdlib.h>

void *free_em(size_t n, ...)
{
    void *s;
    va_list list;

    va_start(list, n);
    while (n--) {
        s = va_arg(list, void *);
        if (!s)
            continue;
        free(s);
    }
    va_end(list);
    return (NULL);
}
