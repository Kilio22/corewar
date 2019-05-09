/*
** EPITECH PROJECT, 2019
** asm
** File description:
** get_last_node
*/

#include "asm.h"

struct instruction *get_last_node(struct instruction *head)
{
    while (head->next)
        head = head->next;
    return head;
}
