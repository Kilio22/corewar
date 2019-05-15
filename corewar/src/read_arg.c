/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** read_arg
*/

#include "corewar.h"

int read_arg(char *arena, int offset, int n)
{
    int arg = arena[offset] & 0b10000000 ? -1 : 0;

    for (int i = 0; i < n; i++) {
        arg <<= 8;
        arg |= arena[offset] & 0b11111111;
        offset = (offset + 1) % MEM_SIZE;
    }
    return arg;
}
