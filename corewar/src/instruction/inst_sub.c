/*
** EPITECH PROJECT, 2019
** inst_sub.c
** File description:
** sub instruction
*/

#include "instruction.h"
#include "corewar.h"

static int is_reg(int reg)
{
    if (reg < 0 || reg > 15)
        return -1;
    return 0;
}

int inst_sub(champion_t *champ, char *arena __attribute__((unused)),
char desc, int *args)
{
    for (int i = 0; i < 3; i++)
        if (is_reg(args[i]) == -1)
            return -1;
    champ->reg[args[2] - 1] = champ->reg[args[0] - 1] - champ->reg[args[1] - 1];
    refresh_carry(champ, champ->reg[args[2] - 1]);
    return 0;
}
