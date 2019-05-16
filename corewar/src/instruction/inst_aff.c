/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_aff
*/

#include "corewar.h"

int inst_aff(champion_t *champ, core_t *core, code_t desc, int *args)
{
    if (is_reg(desc, args, 1) == -1)
        return -1;
    my_printf("%c\n", GET_VAL(0) % 256);
    return 0;
}
