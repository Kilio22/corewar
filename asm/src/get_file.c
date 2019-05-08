/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_file
*/

#include "asm.h"

static void get_full_file(FILE *stream, char ***new)
{
    char *line = NULL;
    char *save = NULL;

    while ((line = get_line(stream)) != NULL) {
        save = line;
        if (!line[0] || line[0] == '#' || !is_empty_line(line)) {
            free(line);
            continue;
        }
        line = skip_whitespaces(line);
        line = delete_end_whitespaces(line);
        *new = my_realloc_array(*new, line);
        if (!(*new))
            return;
        free(save);
    }
}

char **get_file(const char *fp, header_t *header)
{
    char **new = malloc(sizeof(char *) * 1);
    FILE *stream = fopen(fp, "r");

    if (!stream || !new)
        return NULL;
    new[0] = NULL;
    if (get_header(stream, header) == -1) {
        fclose(stream);
        my_free_fields(new);
        return NULL;
    }
    get_full_file(stream, &new);
    fclose(stream);
    if (my_strarraylen(new) < 1) {
        my_free_fields(new);
        return NULL;
    }
    return new;
}