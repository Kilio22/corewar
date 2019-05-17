/*
** EPITECH PROJECT, 2019
** inst_ldi.c
** File description:
** ldi instruction
*/

#include "corewar.h"

int inst_ldi(champion_t *champ, core_t *core, code_t desc, int *args)
{
    int sum;
    int pos;

    // debug(champ, core, desc, args);
    if (is_reg(desc, args, 3) == -1)
        return -1;
    sum = GET_VAL(0);
    if (ARG_TYPE(0) == IDR)
        sum = get_first_two_bytes(sum);
    sum += GET_VAL(1);
    pos = (champ->pc + (sum % IDX_MOD)) % MEM_SIZE;
    while (pos < 0)
        pos += MEM_SIZE;
    champ->reg[args[2] - 1] = read_arg(core->arena, pos, REG_SIZE);
    refresh_carry(champ, champ->reg[args[2] - 1]);
    return 0;
}
