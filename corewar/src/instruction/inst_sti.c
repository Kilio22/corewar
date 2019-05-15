/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_sti
*/

#include "instructions.h"
#include "corewar.h"

int inst_sti(champion_t *champ, char *arena, code_t desc, int *args)
{
    int val[3] = {get_val(champ, arena, MASK(0)),
get_val(champ, arena, MASK(1)), get_val(champ, arena, MASK(2))};

    if (is_reg(desc, args, 3))
        return -1;
    if (ARG_TYPE(1) == IDR)
        val[1] = get_first_two_bytes(val[1]);
    write_arg(arena,
(champ->pc + ((val[1] + val[2]) % IDX_MOD)) % MEM_SIZE, val[0]);
    return 0;
}