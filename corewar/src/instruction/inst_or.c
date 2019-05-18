/*
** EPITECH PROJECT, 2019
** inst_or.c
** File description:
** or intruction
*/

#include "corewar.h"

int inst_or(champion_t *champ, core_t *core, code_t desc, int *args)
{
    if (is_reg(desc, args, 3) == -1)
        return -1;
    champ->reg[args[2] - 1] = GET_VAL(0) | GET_VAL(1);
    refresh_carry(champ, champ->reg[args[2] - 1]);
    return 0;
}
