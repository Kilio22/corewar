/*
** EPITECH PROJECT, 2019
** inst_ld.c
** File description:
** load instruction
*/

#include "corewar.h"

int inst_ld(champion_t *champ, core_t *core, code_t desc, int *args)
{
    // debug(champ, core, desc, args);
    if (is_reg(desc, args, 2) == -1)
        return -1;
    champ->reg[args[1] - 1] = GET_VAL(0);
    refresh_carry(champ, champ->reg[args[1] - 1]);
    return 0;
}
