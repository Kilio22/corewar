/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** get_arg
*/

#include "corewar.h"

const int inst_exeptions[] = {DIR_SIZE, 0, 0, 0, 0, 0, 0, 0,
IND_SIZE, 0, 0, IND_SIZE, 0, 0, IND_SIZE, 0};
const int tab_size[] = {0, 1, DIR_SIZE, 0, IND_SIZE};

int check_index_need(int index)
{
    if (index >= OP_ZJMP && index <= OP_FORK)
        return 1;
    if (index >= OP_LLDI && index <= OP_LFORK)
        return 1;
    return 0;
}

int get_arg_length(char type, int index)
{
    if (type == 0b01)
        return 1;
    if (type == 0b11)
        return IND_SIZE;
    if (type == 0b10) {
        if (check_index_need(index))
            return IND_SIZE;
        return DIR_SIZE;
    }
    return -1;
}

int count_inst_bytes(code_t code, int op_idx)
{
    int bytes = 2;
    int i = 4;
    int tmp = 0;

    if (code == 0 && (op_idx == OP_LIVE || op_idx == OP_ZJMP ||
op_idx == OP_FORK || op_idx == OP_LFORK))
        return 1 + inst_exeptions[op_idx];
    for (; i > op_tab[op_idx].nbr_args; i--)
        code >>= 2;
    for (; i > 0; i--) {
        tmp = find_type(code);
        if (tmp == -1)
            return -1;
        if (tmp == T_DIR && check_index_need(op_idx) == 1)
            bytes += IND_SIZE;
        else
            bytes += tab_size[tmp];
        code >>= 2;
    }
    return bytes;
}