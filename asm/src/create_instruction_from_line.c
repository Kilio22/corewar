/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** create_instruction_from_line
*/

#include "asm.h"

static int add_node(struct instruction *inst, char *str_inst, short id)
{
    struct instruction *last = get_last_inst_node(inst);
    int t_index = find_token_index(str_inst);

    if (!last->instruction) {
        last->instruction = str_inst;
        if (id == ID_LABEL && GET_TOKEN_ID(t_index) == ID_NOTHING)
            last->id = ID_LABEL;
        else
            last->id = GET_TOKEN_ID(t_index);
    } else {
        last->next = create_instruction();
        if (!last->next)
            return -1;
        last = last->next;
        last->instruction = str_inst;
        last->id = GET_TOKEN_ID(t_index);
    }
    last->type = GET_TOKEN_TYPE(t_index);
    return 0;
}

static int add_instruction(struct instruction *inst, char **line, int t_index,
                            size_t i)
{
    char *str_inst = NULL;

    if (GET_TOKEN_TYPE(t_index) == D_NORMAL) {
        str_inst = slice_string(line, i);
        if (!str_inst)
            return -1;
        if (my_strlen(str_inst) == 0) {
            free(str_inst);
            return 0;
        }
    } else
        str_inst = cut_string(line, i);
    if (!str_inst)
        return -1;
    if (my_strlen(str_inst) == 0) {
        free(str_inst);
        str_inst = my_strndup(*line, 1);
        (*line)++;
    }
    return add_node(inst, str_inst, GET_TOKEN_ID(t_index));
}

struct instruction *create_instruction_from_line(char *line)
{
    struct instruction *inst = create_instruction();
    int t_index;

    if (!inst)
        return NULL;
    for (size_t i = 0; line[i]; i++) {
        t_index = find_token_index(line + i);
        if (GET_TOKEN_ID(t_index) == ID_NOTHING)
            continue;
        if (add_instruction(inst, &line, t_index, i) == -1) {
            destroy_instruction(inst);
            return NULL;
        }
        if (GET_TOKEN_TYPE(t_index) == D_COMMENT)
            return inst;
        i = -1;
    }
    if (*line && add_instruction(inst, &line, t_index, my_strlen(line)) == -1)
        return NULL;
    return inst;
}
