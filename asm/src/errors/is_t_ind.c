/*
** EPITECH PROJECT, 2019
** asm
** File description:
** is_t_ind
*/

#include "asm.h"

int is_t_ind(struct instruction *instruction)
{
    if (instruction->id == ID_LABEL) {
        if (!instruction->next || instruction->next->id != ID_NOTHING)
            return 84;
        return T_IND;
    }
    if (!my_str_isnum(instruction->instruction, 1))
        return 84;
    return T_IND;
}