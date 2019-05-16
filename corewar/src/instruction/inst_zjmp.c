/*
** EPITECH PROJECT, 2019
** inst_zjmp.c
** File description:
** z_jump instruction
*/

#include "corewar.h"

int inst_zjmp(champion_t *champ, core_t *core UNU, code_t desc UNU, int *args)
{
    if (champ->carry != 1)
        return 0;
    champ->pc = (champ->pc + (args[0] % IDX_MOD)) % MEM_SIZE;
    while (champ->pc < 0)
        champ->pc += MEM_SIZE;
    return 0;
}
