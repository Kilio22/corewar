/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** coding_bytes
*/

#include "asm.h"

char get_parameters_code(struct instruction *instruction, int index)
{
    char c_bytes = 0;
    int i;

    for (i = 0; i < op_tab[index].nbr_args; i++) {
        if (instruction->id == ID_DIRECT)
            c_bytes += 0b10;
        else if (instruction->instruction[0] == 'r')
            c_bytes += 0b01;
        else
            c_bytes += 0b11;
        if (i < 3)
            c_bytes <<= 2;
        instruction = shift_inst(instruction);
    }
    while (i++ < 3)
        c_bytes <<= 2;
    return c_bytes;
}
