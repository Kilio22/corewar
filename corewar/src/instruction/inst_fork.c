/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_fork
*/

#include "corewar.h"

int inst_lldi(champion_t *champ, core_t *core, code_t desc, int *args)
{
    if (is_reg(desc, args, 3) == -1)
        return -1;
    refresh_carry(champ, champ->reg[args[2] - 1]);
    return 0;
}
