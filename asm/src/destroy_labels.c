/*
** EPITECH PROJECT, 2019
** asm
** File description:
** destroy_labels
*/

#include "asm.h"

static void destroy_label(struct label *ptr)
{
    free(ptr->name);
    free(ptr);
}

void destroy_labels(struct label *head)
{
    struct label *next = head;

    while (head) {
        next = next->next;
        destroy_label(head);
        head = next;
    }
}
