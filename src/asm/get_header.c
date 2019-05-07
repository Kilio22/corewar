/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_header
*/

#include "op.h"
#include "corewar.h"
#include "asm.h"

int get_header(char **file, header_t *header)
{
    if (my_arraylen((void **)file) < 3)
        return -1;
    if (get_name(file, header) == -1)
        return -1;
    if (get_comments(file, header) == -1)
        return -1;
    return 0;
}