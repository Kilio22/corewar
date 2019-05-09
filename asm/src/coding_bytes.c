/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** coding_bytes
*/

#include "asm.h"

static struct instruction *shift_inst(struct instruction *inst)
{
    while (inst && inst->id != ID_SEPARATOR)
        inst = inst->next;
    if (inst)
        inst = inst->next;
    return inst;
}

char get_parameters_code(struct instruction *instruction)
{
    char c_bytes = 0;
    int index = check_instruction_occurences(instruction);

    instruction = instruction->next;
    for (int i = 0; i < index[op_tab].nbr_args; i++) {
        if (instruction->id == ID_DIRECT)
            c_bytes += 0b10;
        else if (instruction->instruction[0] == 'r')
            c_bytes += 0b01;
        else
            c_bytes += 0b11;
        if (i + 1 < index[op_tab].nbr_args)
            c_bytes << 2;
        instruction = shift_inst(instruction);
    }
    return c_bytes;
}