/*
** EPITECH PROJECT, 2019
** check_type.c
** File description:
** check if it's a register
*/

#include "corewar.h"

int get_val(champion_t *champ, char *arena, code_t desc, int val)
{
    if (desc == REG)
        return champ->reg[val - 1];
    if (desc == DIR)
        return val;
    return read_arg(arena, (champ->pc + (val % IDX_MOD)) % MEM_SIZE, REG_SIZE);
}

int get_long_val(champion_t *champ, char *arena, code_t desc, int val)
{
    if (desc == REG)
        return champ->reg[val - 1];
    if (desc == DIR)
        return val;
    return read_arg(arena, (champ->pc + val) % MEM_SIZE, REG_SIZE);
}
