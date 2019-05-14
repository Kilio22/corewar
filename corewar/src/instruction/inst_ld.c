/*
** EPITECH PROJECT, 2019
** inst_ld.c
** File description:
** ld instruction
*/

#include <stdarg.h>
#include "corewar.h"

int inst_ld(champion_t *champ, char *arena __attribute__((unused)),
char args, ...)
{
    va_list list;
    int reg1;
    int reg2;

    va_start(list, args);
    reg1 = va_arg(list, char) - 1;
    reg2 = va_arg(list, char) - 1;
    if (reg2 < 0 || reg2 > 15)
        return -1;
    champ->reg[reg2] = champ->reg[reg1];
    if (champ->reg[reg3] == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    va_end(list);
    return 0;
}
