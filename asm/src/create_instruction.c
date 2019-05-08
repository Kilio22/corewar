/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** create_instruction
*/

#include <stdlib.h>
#include "asm.h"

struct instruction *create_instruction(void)
{
    struct instruction *new = malloc(sizeof(struct instruction));

    if (!new)
        return NULL;
    new->id = ID_NOTHING;
    new->type = D_WITHOUT;
    new->instruction = NULL;
    new->next = NULL;
    return new;
}
