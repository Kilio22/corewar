/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** read_arg
*/

#include "corewar.h"

int read_arg(char *arena, int offset)
{
    int arg = 0;

    for (int i = 0; i < 4; i++) {
        arg <<= 8;
        arg += arena[offset];
        offset = (offset + 1) % MEM_SIZE;
    }
    return arg;
}
