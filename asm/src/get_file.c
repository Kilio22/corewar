/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_file
*/

#include <errno.h>
#include "asm.h"

static int get_full_file(FILE *stream, char ***new)
{
    char *line = NULL;
    char *save = NULL;

    while ((line = get_line(stream)) != NULL) {
        save = line;
        line = skip_whitespaces(line);
        if (!line[0] || line[0] == '#' || !is_empty_line(line)) {
            free(save);
            continue;
        }
        line = delete_end_whitespaces(line);
        *new = my_realloc_array(*new, line);
        if (!(*new))
            return -1;
        free(save);
    }
    if (errno == ENOMEM)
        return -1;
    return 0;
}

char **get_file(const char *fp, header_t *header)
{
    char **new = malloc(sizeof(char *));
    FILE *stream = fopen(fp, "r");

    if (!stream || !new) {
        free(new);
        return NULL;
    }
    new[0] = NULL;
    if (get_header(stream, header) == -1) {
        fclose(stream);
        my_free_fields(new);
        return NULL;
    }
    if (get_full_file(stream, &new) == -1)
        return NULL;
    fclose(stream);
    return new;
}