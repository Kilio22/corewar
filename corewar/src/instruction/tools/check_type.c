/*
** EPITECH PROJECT, 2019
** check_type.c
** File description:
** check if it's a register
*/

#include "instruction.h"
#include "corewar.h"

int check_type(char args)
{
    if (args == 0b01)
        return REG;
    if (args == 0b10)
        return DIR;
    if (args == 0b11)
        return IDR;
    return -1;
}

int get_val(champion_t *champ, char *arena, char desc, int args)
{
    if (check_type((desc & 0b11000000) >> 6) == REG)
        return champ->reg[arg - 1];
    if (check_type((desc & 0b11000000) >> 6) == DIR)
        return arg;
    if (check_type((desc & 0b11000000) >> 6) == IDR)
        return arg + champ->pc;
    return -1;
}
