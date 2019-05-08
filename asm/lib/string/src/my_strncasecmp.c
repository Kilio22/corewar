/*
** EPITECH PROJECT, 2019
** my_strncasecmp.c
** File description:
** Compares two given string pointers for the n first bytes
*/

#include "my_string.h"

int my_strncasecmp(const char *s1, const char *s2, size_t n)
{
    unsigned char c1;
    unsigned char c2;

    if (!s1 || !s2)
        return (-50000);
    if (s1 == s2 || !n)
        return (0);
    while (n--) {
        c1 = (unsigned char) TOLOWER(*s1++);
        c2 = (unsigned char) TOLOWER(*s2++);
        if (c1 != c2)
            return (c1 - c2);
        if (c1 == '\0')
            return (0);
    }
    return (0);
}
