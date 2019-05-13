/*
** EPITECH PROJECT, 2019
** inst_add.c
** File description:
** add intruction
*/

#include <stdarg.h>
#include "corewar.h"

static int is_reg(int reg)
{
    if (reg < 0 || reg > 15)
        return -1;
    return 0;
}

int inst_add(champion_t *champ, char *arena __attribute__((unused)),
char args, ...)
{
    va_list list;
    int reg1;
    int reg2;
    int reg3;

    va_start(list, args);
    reg1 = va_arg(list, char) - 1;
    reg2 = va_arg(list, char) - 1;
    reg3 = va_arg(list, char) - 1;
    if (is_reg(reg1) == -1 || is_reg(reg2) == -1 || is_reg(reg3) == -1)
        return -1;
    champ->reg[reg3] = champ->reg[reg1] + champ->reg[reg2];
    if (champ->reg[reg3] == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    va_end(list);
    return 0;
}
