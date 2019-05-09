/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_labels
*/

#include "asm.h"

static int check_label_occur(struct instruction *list, struct label *head)
{
    if (!list)
        return -1;
    if (!find_label(head, list->instruction))
        return -1;
    return 0;
}

static int check_instruction(struct instruction *list, struct label *head)
{
    int n_val = 0;

    while (list) {
        if (list->id == ID_LABEL)
            n_val += check_label_occur(list->next, head);
        if (n_val == -1)
            return -1;
        list = list->next;
    }
    return n_val;
}

int check_if_labels_exist(struct instruction **list, struct label *head)
{
    int index = 0;

    for (size_t i = 0; list[i]; i++) {
        if (check_instruction(list[i], head) == -1)
            return -1;
    }
    return 0;
}