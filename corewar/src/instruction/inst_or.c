/*
** EPITECH PROJECT, 2019
** inst_or.c
** File description:
** or instruction
*/

#include "instruction.h"
#include "corewar.h"

int inst_or(champion_t *champ, char *arena, char desc, int *args)
{
    if (args[2] < 0 || args[2] > 15)
        return -1;
    get_val(args[2]) = get_val(args[0]) | get_val(args[1]);
    refresh_carry(get_val(args[2]));
    return 0;
}
