/*
** EPITECH PROJECT, 2019
** asm
** File description:
** find_label
*/

#include "asm.h"

struct label *find_label(struct label *head, const char *name)
{
    while (head) {
        if (STR_EQ(head->name, name))
            return head;
        head = head->next;
    }
    return NULL;
}
