/*
** EPITECH PROJECT, 2019
** inst_ldi.c
** File description:
** ldi instruction
*/

#include "corewar.h"

int inst_ldi(champion_t *champ, char *arena, code_t desc, int *args)
{
    int index = args[0] + args[1];

    if (is_reg(desc, args, 3) == -1)
        return -1;
    champ->reg[index - 1] = get_val(champ, arena, MASK(0))
+ get_val(champ, arena, MASK(1));
    return 0;
}
