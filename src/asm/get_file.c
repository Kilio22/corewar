/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_file
*/

#include "corewar.h"

const char *valid = " \t";

static int is_empty_line(const char *line)
{
    for (size_t i = 0; line[i]; i++) {
        if (!my_strchr((char *)valid, line[i]))
            return -1;
    }
    return 0;
}

char **get_file(const char *fp)
{
    char *line = NULL;
    char **new = malloc(sizeof(char *) * 1);
    FILE *stream;

    stream = fopen(fp, "r");
    if (!stream || !new || !my_str_ends_with(fp, ".s"))
        return NULL;
    new[0] = NULL;
    while ((line = get_line(stream)) != NULL) {
        if (!line[0] || line[0] == '#' || !is_empty_line(line)) {
            free(line);
            continue;
        }
        new = my_realloc_array(new, line);
    }
    return new;
}