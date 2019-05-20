/*
** EPITECH PROJECT, 2019
** inst_st.c
** File description:
** store intruction
*/

#include "corewar.h"

int inst_st(champion_t *champ, core_t *core, code_t desc, int *args)
{
    int pos;

    if (is_reg(desc, args, 2) == -1)
        return -1;
    if (ARG_TYPE(1) == REG)
        champ->reg[args[1] - 1] = GET_VAL(0);
    else {
        pos = (champ->pc + (args[1] % IDX_MOD)) % MEM_SIZE;
        while (pos < 0)
            pos += MEM_SIZE;
        write_arg(core->arena, pos, GET_VAL(0));
    }
    return 0;
}
