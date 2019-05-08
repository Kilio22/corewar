/*
** EPITECH PROJECT, 2019
** my_strchr.c
** File description:
** Returns a pointer to the first occurence of a given char in the given string
*/

#include "my_string.h"

char *my_strchr(char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s) {
        if (*s == c)
            return (s);
        s++;
    }
    return (NULL);
}
