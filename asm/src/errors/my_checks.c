/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_comas
*/

#include "asm.h"

static int check_chars(char *str, char *to_compare)
{
    for (size_t i = 0; str[i]; i++) {
        if (!my_strchr(to_compare, str[i]))
            return -1;
    }
    return 0;
}

int check_labels(struct instruction *instruction)
{
    if (check_chars(instruction->instruction, LABEL_CHARS))
        return 84;
    return 0;
}

int check_instruction_occurences(char *instruction)
{
    int index = -1;

    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (my_strcmp(instruction, op_tab[i].mnemonique) == 0)
            index = i;
    return index;
}

int check_comas(struct instruction *instruction, int nb)
{
    int i = 0;

    if (instruction->id == ID_SEPARATOR)
        return 84;
    while (instruction) {
        if (instruction->id == ID_SEPARATOR && (!instruction->next ||
instruction->next->id == ID_SEPARATOR))
            return 84;
        if (instruction->id == ID_SEPARATOR)
            i++;
        instruction = instruction->next;
    }
    if (i != nb - 1)
        return 84;
    return 0;
}

int check_type(struct instruction *instruction)
{
    if (instruction->id == ID_DIRECT)
        return is_t_dir(instruction->next);
    else if (instruction->instruction[0] == 'r')
        return is_t_reg(instruction);
    else
        return is_t_ind(instruction);
}