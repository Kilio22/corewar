/*
** EPITECH PROJECT, 2019
** asm
** File description:
** get_labels
*/

#include "asm.h"

static void shift_instructions(struct instruction **list)
{
    struct instruction *ptr;

    for (size_t i = 1; list[i]; i++) {
        ptr = list[i - 1];
        list[i - 1] = list[i];
        list[i] = ptr;
    }
}

static int add_label(struct label **head, char *name, int offset)
{
    struct label *new = create_label(name, offset);
    struct label *last;

    if (!new)
        return -1;
    if (!*head) {
        *head = new;
        return 0;
    }
    last = get_last_label_node(*head);
    last->next = new;
    return 0;
}

static int check_if_label(struct instruction **inst, struct label **head,
                            int offset)
{
    struct instruction *ptr = *inst;
    int n = 2;

    if ((*inst)->id != ID_LABEL)
        return 0;
    if (add_label(head, (*inst)->instruction, offset) == -1)
        return -1;
    while (n--) {
        *inst = (*inst)->next;
        destroy_instruction(ptr);
        ptr = *inst;
    }
    return 0;
}

int get_labels(struct instruction **list, struct label **head)
{
    int offset = 0;

    for (size_t i = 0; list[i]; i++) {
        if (check_if_label(&list[i], head, offset) == -1)
            return -1;
        if (!list[i]) {
            shift_instructions(&list[i--]);
            continue;
        }
        offset += count_instruction_bytes(list[i]);
    }
    return offset;
}
