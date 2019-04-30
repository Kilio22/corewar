/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm
*/

#include "op.h"

int launch_asm(char *filepath)
{
    char **file = read_file(filepath);
    char *file_dest;
    int n_return = 0;

    if (!file)
        return -1;
    file_dest = create_dest_filename(filepath);
    if (!file_dest)
        return -1;
    if (compile_file(file, file_dest) == -1)
        n_return = -1;
    free(file_dest);
    my_free_fields(file);
    return n_return;
}
