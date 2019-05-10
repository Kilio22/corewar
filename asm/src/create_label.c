/*
** EPITECH PROJECT, 2019
** asm
** File description:
** create_label
*/

#include "asm.h"

struct label *create_label(char *name, int offset)
{
    struct label *new = malloc(sizeof(struct label));

    if (!new)
        return NULL;
    new->name = my_strdup(name);
    if (!new->name)
        return NULL;
    new->offset = offset;
    new->next = NULL;
    return new;
}
