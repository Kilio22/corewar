/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** load_instructions
*/

#include "asm.h"

static struct instruction **realloc_instruction_list(struct instruction **list,
                                                        struct instruction *new)
{
    size_t len = my_arraylen((void **) list) + 2;
    struct instruction **new_list = malloc(sizeof(struct instruction *) * len);
    size_t i = 0;

    if (!new_list)
        return NULL;
    for (;list[i]; i++)
        new_list[i] = list[i];
    new_list[i++] = new;
    new_list[i] = NULL;
    free(list);
    return new_list;
}

struct instruction **load_instruction(char **file)
{
    struct instruction **list = malloc(sizeof(struct instruction *));
    struct instruction *new;

    if (!list)
        return NULL;
    *list = NULL;
    for (size_t i = 0; file[i]; i++) {
        new = create_instruction_from_line(file[i]);
        if (!new)
            return NULL;
        list = realloc_instruction_list(list, new);
        if (!list)
            return NULL;
    }
    return list;
}
