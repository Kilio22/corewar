/*
** EPITECH PROJECT, 2019
** inst_st.c
** File description:
** store intruction
*/

#include "instruction.h"
#include "corewar.h"

int inst_st(champion_t *champ, char *arena, char desc, int *args)
{
    if (args[0] < 0 || args[0] > 15)
        return -1;
    if (check_type((desc & 0b00110000) << 2 >> 6) == REG) {
        if (args[1] < 0 || args[1] > 15)
            return -1;
        champ->reg[args[0] - 1] = champ->reg[args[1] - 1];
    }
    else
        champ->reg[args[0] - 1] = arena[(champ->pc + args[1] % IDX_MOD) % MEM_SIZE];
    return 0;
}
