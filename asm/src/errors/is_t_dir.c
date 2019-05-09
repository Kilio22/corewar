/*
** EPITECH PROJECT, 2019
** asm
** File description:
** is_t_dir
*/

#include "asm.h"

int is_t_dir(struct instruction *instruction)
{
    if (!instruction)
        return 84;
    if (instruction->id == ID_NOTHING) {
        if (!my_str_isnum(instruction->instruction, 1))
            return 84;
        return T_DIR;
    } else if (instruction->id == ID_LABEL) {
        if (!instruction->next || instruction->next->id != ID_NOTHING)
            return 84;
        return T_DIR;
    } else
        return 84;
}