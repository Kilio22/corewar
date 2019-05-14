/*
** EPITECH PROJECT, 2019
** inst_add.c
** File description:
** add intruction
*/

#include "instruction.h"
#include "corewar.h"

static int is_reg(int reg)
{
    if (reg < 0 || reg > 15)
        return -1;
    return 0;
}

int inst_add(champion_t *champ, char *arena __attribute__((unused)),
char desc, int *args)
{
    for (int i = 0; i < 3; i++)
        if (is_reg(args[i]) == -1)
            return -1;
    get_val(args[2]) = get_val(args[0]) + get_val(args[1]);
    refresh_carry(champ, get_val(args[2]));
    return 0;
}
