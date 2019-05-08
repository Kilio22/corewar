/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_handling
*/

#include "asm.h"

int check_chars(char *str, char *to_compare)
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
    int before = 1;

    if (instruction->id = ID_SEPARATOR)
        return 84;
    while (instruction) {
        if (instruction->id == ID_SEPARATOR
&& instruction->next->id == ID_SEPARATOR)
            return 84;
        if (instruction->id == ID_SEPARATOR)
            i++;
        instruction = instruction->next;
    }
    if (i != nb - 1)
        return 84;
    return 0;
}

int is_t_dir(struct instruction *instruction)
{
    if (!instruction)
        return 84;
    if (instruction->id == ID_NOTHING) {
        if (!my_str_isnum(instruction->instruction, 1))
            return 84;
        return T_DIR;
    } else if (instruction->id == ID_LABEL) {
        if (!instruction->next || instruction->next->id != ID_NOTHING)
            return 84;
        return T_DIR;
    } else
        return 84;
}

int is_t_reg(struct instruction *instruction)
{
    if (my_strlen(&instruction->instruction[1]) == 0)
        return 84;
    if (!my_str_isnum(&instruction->instruction[1], 0))
        return 84;
    if (my_atoi(instruction->instruction) < 1
|| my_atoi(instruction->instruction) > REG_NUMBER)
        return 84;
    return T_REG;
}

int is_t_ind(struct instruction *instruction)
{
    if (instruction->id == ID_LABEL) {
        if (!instruction->next || instruction->next->id != ID_NOTHING)
            return 84;
        return T_IND;
    }
    if (!my_str_isnum(instruction->instruction, 1))
        return 84;
    return T_IND;
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

int check_instruction(struct instruction *instruction)
{
    int type = 0;
    int index = check_instruction_occurences(instruction->instruction);
    struct instruction *save = instruction;

    if (index == -1)
        return 84;
    instruction = instruction->next;
    if (!instruction)
        return 84;
    if (check_comas(instruction, op_tab[index].nbr_args) == 84)
        return 84;
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        type = check_type(instruction);
        if (type == 84)
            return 84;
        if (op_tab[index].type[i] != type)
            return 84;
        type = 0;
    }
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
    }
    else
        return check_instruction(instruction);
    return 0;
}

int check_syntax_loop(struct instruction **instruction)
{
    size_t offset = 0;

    for (size_t i = 0; instruction[i]; i++) {
        if (instruction[i]->type != D_WITHOUT)
            return 84;
        if (check_syntax(instruction[i]) == 84)
            return 84;
    }
}