/*
** EPITECH PROJECT, 2019
** my_strcasecmp.c
** File description:
** Compares two given string pointers
*/

#include "my_string.h"

int my_strcasecmp(const char *s1, const char *s2)
{
    unsigned char c1;
    unsigned char c2;

    if (!s1 || !s2)
        return (-50000);
    if (s1 == s2)
        return (0);
    do {
        c1 = (unsigned char) TOLOWER(*s1++);
        c2 = (unsigned char) TOLOWER(*s2++);
        if (c1 == '\0')
            return (c1 - c2);
    } while (c1 == c2);
    return (c1 - c2);
}
