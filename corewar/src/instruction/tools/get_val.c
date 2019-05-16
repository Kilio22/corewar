/*
** EPITECH PROJECT, 2019
** check_type.c
** File description:
** check if it's a register
*/

#include "corewar.h"

int get_val(champion_t *champ, char *arena, code_t desc, int val)
{
    int dest;

    if (desc == REG)
        return champ->reg[val - 1];
    if (desc == DIR)
        return val;
    dest = (champ->pc + (val % IDX_MOD)) % MEM_SIZE;
    while (dest < 0)
        dest += MEM_SIZE;
    return read_arg(arena, dest, REG_SIZE);
}

int get_long_val(champion_t *champ, char *arena, code_t desc, int val)
{
    int dest;

    if (desc == REG)
        return champ->reg[val - 1];
    if (desc == DIR)
        return val;
    dest = (champ->pc + val) % MEM_SIZE;
    while (dest < 0)
        dest += MEM_SIZE;
    return read_arg(arena, dest, REG_SIZE);
}
