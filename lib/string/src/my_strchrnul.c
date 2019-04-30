/*
** EPITECH PROJECT, 2019
** my_strchrnul.c
** File description:
** Returns a pointer to the first occurence of a given char in the given string
*/

#include "my_string.h"

char *my_strchrnul(char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s) {
        if (*s == c)
            break;
        s++;
    }
    return (s);
}
