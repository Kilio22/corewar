/*
** EPITECH PROJECT, 2019
** asm
** File description:
** get_parameters_size
*/

#include "asm.h"

int get_parameter_size(struct instruction *inst, int index)
{
    if (inst->id == ID_DIRECT) {
        if (check_index_need(index) == 1)
            return IND_SIZE;
        else
            return DIR_SIZE;
    } else if (inst->instruction[0] == 'r')
        return 1;
    else
        return IND_SIZE;
}