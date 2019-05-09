/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_line
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

char *get_line(FILE *f_stream)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t n_read;

    n_read = getline(&line, &n, f_stream);
    if (n_read == -1) {
        free(line);
        return NULL;
    }
    if (line[n_read - 1] == '\n')
        line[n_read - 1] = '\0';
    return line;
}
