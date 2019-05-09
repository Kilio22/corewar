/*
** EPITECH PROJECT, 2019
** asm
** File description:
** shift_inst
*/

#include "asm.h"

struct instruction *shift_inst(struct instruction *inst)
{
    while (inst && inst->id != ID_SEPARATOR)
        inst = inst->next;
    if (inst)
        inst = inst->next;
    return inst;
}
