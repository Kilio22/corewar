/*
** EPITECH PROJECT, 2019
** inst_ld.c
** File description:
** load instruction
*/

#include "corewar.h"

int inst_ld(champion_t *champ, char *arena, char desc, int *args)
{
    if (is_reg(args) == -1)
        return -1;
    champ->reg[args[1] - 1] = get_val(champ, arena, desc, args);
    refresh_carry(champ->reg[args[1] - 1])
    return 0;
}
