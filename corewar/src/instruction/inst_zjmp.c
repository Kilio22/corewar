/*
** EPITECH PROJECT, 2019
** inst_zjmp.c
** File description:
** z_jump instruction
*/

#include "corewar.h"

int inst_zjmp(champion_t *champ, char *arena, code_t desc, int *args)
{
    int jump = args[0] % IDX_MOD;

    if (champ->carry != 1)
        return 0;
    else {
        if (jump < 0)
            champ->pc = (champ->pc + jump - MEM_SIZE) % MEM_SIZE;
        else
            champ->pc = (champ->pc + jump) % MEM_SIZE;
    }
    return 0;
}
