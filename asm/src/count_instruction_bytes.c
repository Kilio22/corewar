/*
** EPITECH PROJECT, 2019
** asm
** File description:
** count_instruction_bytes
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

static int check_index_need(int index)
{
    if (index >= 8 && index <= 11)
        return 1;
    return 0;
}

int count_instruction_bytes(struct instruction *inst)
{
    int size = 2;
    int index = check_instruction_occurences(inst->instruction);

    if (op_tab[index].nbr_args == 1)
        --size;
    inst = inst->next;
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        if (inst->id == ID_DIRECT) {
            if (check_index_need(index) == 1)
                size += IND_SIZE;
            else
                size += DIR_SIZE;
        } else if (inst->instruction[0] == 'r')
            size += 1;
        else
            size += IND_SIZE;
        inst = shift_inst(inst);
    }
    return size;
}
