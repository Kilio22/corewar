/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_handling
*/

#include "asm.h"

static int check_next(struct instruction **instruction, int *type)
{
    if (!(*instruction)->next)
            return 0;
    if ((*type) == T_DIR && (*instruction)->next->id == ID_LABEL)
        (*instruction) = (*instruction)->next->next;
    else if (((*type) == T_DIR && (*instruction)->next->id != ID_LABEL)
|| ((*type) == T_IND && (*instruction)->id == ID_LABEL))
        (*instruction) = (*instruction)->next;
    if (!(*instruction))
        return 0;
    (*instruction) = (*instruction)->next;
    (*type) = 0;
    if (!(*instruction))
        return 0;
    if ((*instruction)->id != ID_SEPARATOR)
        return 84;
    (*instruction) = (*instruction)->next;
    return 1;
}

int check_instruction(struct instruction *instruction)
{
    int n_val = 1;
    int type = 0;
    int index = check_instruction_occurences(instruction->instruction);

    if (index == -1 || !instruction->next)
        return 84;
    instruction = instruction->next;
    if (check_comas(instruction, op_tab[index].nbr_args) == 84)
        return 84;
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        type = check_type(instruction);
        if (type == 84)
            return 84;
        if (!(type & op_tab[index].type[i]))
            return 84;
        n_val = check_next(&instruction, &type);
        if (n_val == 0 || n_val == 84)
            return n_val;
    }
    return 0;
}

int check_syntax(struct instruction *instruction)
{
    if (!instruction || !instruction->next)
        return 84;
    if (instruction->next->id == ID_LABEL) {
        if (check_labels(instruction) == 84)
            return 84;
        instruction = instruction->next->next;
        if (!instruction)
            return 0;
        if (check_instruction(instruction) == 84)
            return 84;
    } else
        return check_instruction(instruction);
    return 0;
}

int check_syntax_loop(struct instruction **instruction)
{
    for (size_t i = 0; instruction[i]; i++) {
        if (instruction[i]->id != ID_NOTHING)
            return 84;
        if (check_syntax(instruction[i]) == 84)
            return 84;
    }
    return 0;
}
