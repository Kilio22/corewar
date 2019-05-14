/*
** EPITECH PROJECT, 2019
** inst_ld.c
** File description:
** load instruction
*/

#include "corewar.h"

int inst_ld(champion_t *champ, char *arena, char desc, int *args)
{
    if (args[1] < 0 || args[1] > 15)
        return -1;
    champ->reg[args[1] - 1] = arena[pc + args[0] - 1];
    refresh_carry(champ->reg[args[1] - 1])
    return 0;
}
