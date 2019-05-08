/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** create_instruction_from_line
*/

#include "asm.h"

static int find_token_index(char c)
{
    for (int i = 0; i < ID_NUMBER; i++)
        if (c == token_tab[i].delimit)
            return i;
    return -1;
}

struct instruction *add_instruction(char *instruction, enum id_delimiters id)
{
    struct instruction *inst = malloc(sizeof(struct instruction));

    inst->instruction = NULL;
    inst->id = 0;
    inst->next = NULL;
}

struct instruction *slice_instruction(struct instruction *inst, char *line)
{
    
}

static struct instruction *analyse_token(struct instruction *inst, short type)
{
    if (type == D_NORMAL)
        ;
    if (type == D_SEPARATOR)
        ;
}

struct instruction **create_instruction_from_line(char *line)
{
    struct instruction *inst = NULL;
    char *begin = line;
    int t_index;

    if (!inst)
        return NULL;
    inst->id = ID_WITHOUT;
    inst->type = ID_WITHOUT;
    for (size_t i = 0; line[i]; i++) {
        t_index = find_token_index(line[i]);
        if (t_index == -1)
            continue;
        inst = add_instruction(my_strndup(begin, line + i - begin), );
    }
    return inst;
}
