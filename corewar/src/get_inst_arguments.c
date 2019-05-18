/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** get_inst_arguments
*/

#include "corewar.h"

static int get_arg(char *arena, char type, int op_idx, int *offset)
{
    int arg_len = get_arg_length(type, op_idx);
    int arg = read_arg(arena, *offset, arg_len);

    *offset = (*offset + arg_len) % MEM_SIZE;
    return arg;
}

void get_inst_arguments(char *arena, int arg[4], int op_idx, int pc)
{
    code_t code = arena[(pc + 1) % MEM_SIZE];
    char type = 0;
    int offset = (pc + 2) % MEM_SIZE;

    if (!op_needs_args(op_idx)) {
        if (--offset < 0)
            offset += MEM_SIZE;
        arg[0] = get_arg(arena, op_idx == OP_LIVE ? 0b10 : 0b11, op_idx,
&offset);
        return;
    }
    for (int i = 0; i < op_tab[op_idx].nbr_args; i++) {
        type = (code & 0b11000000) >> 6;
        arg[i] = get_arg(arena, type, op_idx, &offset);
        code <<= 2;
    }
}
