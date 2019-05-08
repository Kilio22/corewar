/*
** EPITECH PROJECT, 2018
** my_dprintf.c
** File description:
** Shitty but fast dprintf
*/

#include <stdarg.h>
#include "my.h"
#include "my_stdio.h"

static int print_flag(int fd, char mode, va_list list)
{
    if (mode == 'd')
        return (my_dputs(my_itoa(va_arg(list, int)), fd));
    if (mode == 's')
        return (my_dputs(va_arg(list, char *), fd));
    if (mode == '%')
        return (my_putchar('c'));
    return (0);
}

int my_dprintf(int fd, const char *format, ...)
{
    va_list list;
    int len = 0;

    va_start(list, format);
    while (*format) {
        if (*format == '%')
            len += print_flag(fd, *++format, list);
        else
            len += my_dputc(*format, fd);
        format++;
    }
    va_end(list);
    return (len);
}
