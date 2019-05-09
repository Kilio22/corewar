/*
** EPITECH PROJECT, 2019
** asm
** File description:
** destroy_instructions
*/

#include <stdlib.h>
#include "asm.h"

void destroy_instruction(struct instruction *inst)
{
    struct instruction *head = inst;

    while (head) {
        inst = inst->next;
        free(head->instruction);
        free(head);
        head = inst;
    }
}

void destroy_instruction_list(struct instruction **list)
{
    for (struct instruction *ptr = *list; ptr; ptr++)
        destroy_instruction(ptr);
    free(list);
}
