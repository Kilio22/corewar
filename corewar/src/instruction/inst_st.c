/*
** EPITECH PROJECT, 2019
** inst_st.c
** File description:
** store intruction
*/

#include "corewar.h"

int inst_st(champion_t *champ, char *arena, code_t desc, int *args)
{
    int val;

    if (is_reg(desc, args) == -1)
        return -1;
    val = get_val(champ, arena, MASK(0));
    if (ARG_TYPE(1) == REG)
        champ->reg[args[1] - 1] = val;
    else
        write_arg(arena, (champ->pc + (args[1] % IDX_MOD)) % MEM_SIZE, val);
    refresh_carry(champ, val);
    return 0;
}
