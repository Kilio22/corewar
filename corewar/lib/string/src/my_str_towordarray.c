/*
** EPITECH PROJECT, 2019
** my_str_towordarray.c
** File description:
** Split a string pointer every char in delim into an array of pointers
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"

static void clean_str(char *str, const char c, char const *end_ptr)
{
    while (str < end_ptr) {
        str = my_strchrnul(str, c);
        *str++ = '\0';
    }
}

static char *skip_blanks(char *str, char const *end_ptr)
{
    while (!*str && str < end_ptr)
        str++;
    return (str);
}

static size_t count_word_nb(char *str, char const *end_ptr)
{
    size_t nb_count = 0;

    str = skip_blanks(str, end_ptr);
    while (str < end_ptr) {
        if (*str)
            nb_count++;
        while (*str)
            str++;
        str = skip_blanks(str, end_ptr);
    }
    return (nb_count);
}

static int fill_wordarray(char **array, char *str, char const *end_ptr)
{
    while (str < end_ptr) {
        *array = my_strdup(str);
        if (*array == NULL)
            return (0);
        while (*str)
            str++;
        str = skip_blanks(str, end_ptr);
        array++;
    }
    *array = NULL;
    return (1);
}

char **my_str_towordarray(char *src, const char *delim)
{
    char **array;
    char const *end_ptr;
    char *str = my_strdup(src);

    if (!str)
        return (NULL);
    end_ptr = str + my_strlen(str);
    while (*delim)
        clean_str(str, *delim++, end_ptr);
    array = malloc(sizeof(char *) * (count_word_nb(str, end_ptr) + 1));
    if (!array)
        return (NULL);
    if (fill_wordarray(array, skip_blanks(str, end_ptr), end_ptr) == 0)
        return (NULL);
    free(str);
    return (array);
}
