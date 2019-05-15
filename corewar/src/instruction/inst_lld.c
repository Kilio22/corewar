/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_lld
*/

#include "corewar.h"

int inst_lld(champion_t *champ, char *arena, code_t desc, int *args)
{
    if (is_reg(desc, args, 2) == -1)
        return -1;
    champ->reg[args[1] - 1] = get_long_val(champ, arena, MASK(0));
    refresh_carry(champ, champ->reg[args[1] - 1]);
    return 0;
}