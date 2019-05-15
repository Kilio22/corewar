/*
** EPITECH PROJECT, 2019
** inst_ldi.c
** File description:
** ldi instruction
*/

#include "instructions.h"
#include "corewar.h"

int inst_ldi(champion_t *champ, char *arena, code_t desc, int *args)
{
    int val[3] = {get_val(champ, arena, MASK(0)),
get_val(champ, arena, MASK(1)), get_val(champ, arena, MASK(2))};
    int s;

    if (is_reg(desc, args, 3) == -1)
        return -1;
    if (ARG_TYPE(0) == IDR)
        val[0] = get_first_two_bytes(val[0]);
    s = val[0] + val[1];
    champ->reg[val[2]] =
read_arg(arena, (champ->pc + (s % IDX_MOD)) % MEM_SIZE);
    refresh_carry(champ, champ->reg[val[2]]);
    return 0;
}
