/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "op.h"
#include "my_stdio.h"
#include "my_string.h"
#include "corewar.h"

char **read_file(char *filepath)
{
    FILE *fstream = fopen(filepath, "r");
    char **file = malloc(sizeof(char *));

    if (!fstream || !file)
        return NULL;
    *file = NULL;
    for (char *line = get_line(fstream); line; line = get_line(fstream)) {
        if (!*line || *line == COMMENT_CHAR) {
            free(line);
            continue;
        }
        file = my_realloc_array(file, line);
        if (!file)
            return NULL;
    }
    return file;
}

char *get_inscruction_name(char *line)
{
    size_t i = 0;

    while (line[i] && line[i] != ' ')
        i++;
    if (!line[i])
        return NULL;
    return my_strndup(line, i);
}

int write_command(char *cmd, int fd)
{
    int n_cmd = 0;

    (void) fd;
    if (!my_strncmp(cmd, NAME_CMD_STRING, NAME_CMD_LEN))
        n_cmd = 1;
    else if (!my_strncmp(cmd, COMMENT_CMD_STRING, COMMENT_CMD_LEN))
        n_cmd = 1;
    if (!n_cmd)
        return -1;
    return 0;
}

char **get_inscruction_arguments(char *line)
{
    char **array;

    while (*line != ' ')
        line++;
    array = my_str_towordarray(++line, SEPARATOR_STR);
    if (!array)
        return NULL;
    return array;
}

int compile_line(char *line, int fd)
{
    char **args;
    char *inscruction;

    if (*line == '.') {
        if (write_command(line, fd) == -1)
            return -1;
        return 0;
    }
    inscruction = get_inscruction_name(line);
    if (inscruction) {
        args = get_inscruction_arguments(line);
        if (!args)
            return -1;
        printf("Inscruction : %s\n", inscruction);
        my_show_wordarray(args);
        puts("");
        free(inscruction);
        my_free_fields(args);
    }
    return 0;
}

char *create_dest_filename(char *filepath)
{
    size_t len = my_strlen(filepath);

    if (my_str_ends_with(filepath, ".s"))
        len -= 2;
    return my_strcat(my_strndup(filepath, len), my_strdup(".cor"));
}

static void display_help(void)
{
    my_puts("USAGE");
    my_puts("\t./asm file_name[.s]");
    my_puts("DESCRIPTION");
    my_putstr("\tfile_name\tfile in assembly language to be converted into ");
    my_puts("file_name.cor, an\n\t\t\texecutable in the Virtual Machine.");
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        my_puts("Please give a file to compile");
        return 84;
    }
    if (STR_EQ("-h", argv[1])) {
        display_help();
        return 0;
    }
    if (launch_asm(argv[1]) == -1)
        return 84;
    return 0;
}
