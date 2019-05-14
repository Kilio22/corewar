/*
** EPITECH PROJECT, 2019
** inst_st.c
** File description:
** store intruction
*/

#include "corewar.h"

int inst_st(champion_t *champ, char *arena, char desc, int *args)
{
    if (is_reg(args) == -1)
        return -1;
    champ->reg[args[1] - 1] = get_val(champ, arena, desc, args);
    refresh_carry(champ, champ->reg[args[2] - 1]);
    return 0;
}
