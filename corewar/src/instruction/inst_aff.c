/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_aff
*/

#include "corewar.h"

int inst_aff(champion_t *champ, char *arena, code_t desc, int *args)
{
    int val = get_val(champ, arena, MASK(0));

    if (is_reg(desc, args, 1))
        return -1;
    val %= 256;
    my_printf("%c\n", val);
    return 0;
}