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
    if (bit_code == 0b01)
        return REG;
    if (bit_code == 0b10)
        return DIR;
    if (bit_code == 0b11)
        return IDR;
    return -1;
}
