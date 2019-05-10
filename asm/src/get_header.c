/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** get_header
*/

#include <errno.h>
#include "asm.h"

static int get_comment(char *line, header_t *header)
{
    size_t i = 0;

    if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))
|| (line[my_strlen(COMMENT_CMD_STRING)] != ' '
&& line[my_strlen(COMMENT_CMD_STRING)] != '\t'))
        return -1;
    if (line[my_strlen(line) - 1] != '"')
        return -1;
    line = skip_whitespaces(&line[my_strlen(COMMENT_CMD_STRING)]);
    if (*line != '"')
        return -1;
    line++;
    if (my_quote_len(line) > COMMENT_LENGTH)
        return -1;
    for (; line[i] && line[i] != '"'; i++)
        header->comment[i] = line[i];
    header->comment[i] = '\0';
    return 0;
}

static int get_name(char *line, header_t *header)
{
    size_t i = 0;

    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING))
|| (line[my_strlen(NAME_CMD_STRING)] != ' '
&& line[my_strlen(NAME_CMD_STRING)] != '\t'))
        return -1;
    if (line[my_strlen(line) - 1] != '"')
        return -1;
    line = skip_whitespaces(&line[my_strlen(NAME_CMD_STRING)]);
    if (*line != '"')
        return -1;
    line++;
    if (my_quote_len(line) > PROG_NAME_LENGTH)
        return -1;
    for (; line[i] && line[i] != '"'; i++)
        header->prog_name[i] = line[i];
    header->prog_name[i] = '\0';
    return 0;
}

static int geter_head(char *line, char *save, header_t *header, size_t *i)
{
    int n_val = 0;

    line = skip_whitespaces(line);
    line = delete_end_whitespaces(line);
    n_val = ((*i) == 0) ? get_name(line, header) : get_comment(line, header);
    free(save);
    if (n_val)
        return -1;
    (*i)++;
    return 0;
}

static char *read_next_line(char **line, FILE *stream)
{
    *line = get_line(stream);
    return *line;
}

int get_header(FILE *stream, header_t *header)
{
    char *line = get_line(stream);
    char *save = line;
    size_t i = 0;

    while (line) {
        if (line[0] == '#' || !is_empty_line(line)) {
            free(save);
            save = read_next_line(&line, stream);
            continue;
        }
        if (geter_head(line, save, header, &i) == -1)
            return -1;
        if (i >= 2)
            break;
        save = read_next_line(&line, stream);
    }
    if (i < 2 || errno == ENOMEM)
        return -1;
    return 0;
}