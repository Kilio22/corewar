/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_lld
*/

#include "corewar.h"

int inst_lld(champion_t *champ, core_t *core, code_t desc, int *args)
{
    // debug(champ, core, desc, args);
    if (is_reg(desc, args, 2) == -1)
        return -1;
    champ->reg[args[1] - 1] = GET_LVAL(0);
    refresh_carry(champ, champ->reg[args[1] - 1]);
    return 0;
}
