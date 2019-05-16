/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_sti
*/

#include "corewar.h"

int inst_sti(champion_t *champ, core_t *core, code_t desc, int *args)
{
    // debug(champ, core, desc, args);
    int sum;
    int pos;

    if (is_reg(desc, args, 3) == -1)
        return -1;
    sum = GET_VAL(1);
    if (ARG_TYPE(1) == IDR)
        sum = get_first_two_bytes(sum);
    sum += GET_VAL(2);
    pos = (champ->pc + (sum % IDX_MOD)) % MEM_SIZE;
    while (pos < 0)
        pos += MEM_SIZE;
    write_arg(core->arena, pos, GET_VAL(0));
    return 0;
}
