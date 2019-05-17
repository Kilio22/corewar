/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** write_arg
*/

#include <endian.h>
#include "corewar.h"

void write_arg(char *arena, int offset, int val)
{
    char byte;

    val = htobe32(val);
    for (int i = 0; i < 4; i++) {
        byte = val & 0b11111111;
        val >>= 8;
        arena[offset] = byte;
        offset = (offset + 1) % MEM_SIZE;
    }
}
