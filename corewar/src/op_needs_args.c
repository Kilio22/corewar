/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** op_needs_args
*/

#include "corewar.h"

bool op_needs_args(int op_idx)
{
    if (op_idx == OP_LIVE || op_idx == OP_ZJMP)
        return false;
    if (op_idx == OP_FORK || op_idx == OP_LFORK)
        return false;
    return true;
}
