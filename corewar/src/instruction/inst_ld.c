/*
** EPITECH PROJECT, 2019
** inst_ld.c
** File description:
** load instruction
*/

#include "corewar.h"

int inst_ld(champion_t *champ, char *arena, code_t desc, int *args)
{
    if (is_reg(desc, args) == -1)
        return -1;
    champ->reg[args[1] - 1] = get_val(champ, arena, MASK(0));
    refresh_carry(champ, champ->reg[args[1] - 1]);
    return 0;
}
