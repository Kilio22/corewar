/*
** EPITECH PROJECT, 2019
** is_reg.c
** File description:
** check if args are regs
*/

#include "corewar.h"

int is_reg(code_t desc, int *args, int nb_arg)
{
    for (int i = 0; i < nb_arg; i++) {
        if (ARG_TYPE(i) != REG)
            continue;
        if (args[i] < 1 || args[i] > 16)
            return -1;
    }
    return 0;
}
