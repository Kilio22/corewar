/*
** EPITECH PROJECT, 2019
** asm
** File description:
** is_t_reg
*/

#include "asm.h"

int is_t_reg(struct instruction *instruction)
{
    if (my_strlen(&instruction->instruction[1]) == 0)
        return 84;
    if (!my_str_isnum(&instruction->instruction[1], 0))
        return 84;
    if (my_atoi(&instruction->instruction[1]) < 1
|| my_atoi(&instruction->instruction[1]) > REG_NUMBER)
        return 84;
    return T_REG;
}