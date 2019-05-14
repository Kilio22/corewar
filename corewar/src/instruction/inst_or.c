/*
** EPITECH PROJECT, 2019
** inst_or.c
** File description:
** or intruction
*/

#include "corewar.h"

int inst_or(champion_t *champ, char *arena, code_t desc, int *args)
{
    if (is_reg(desc, args) == -1)
        return -1;
    champ->reg[args[2] - 1] = get_val(champ, arena, MASK(0)) |
get_val(champ, arena, MASK(1));
    refresh_carry(champ, champ->reg[args[2] - 1]);
    return 0;
}
