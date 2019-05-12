/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** check_overlap
*/

#include "corewar.h"

static int overlap_conditions(champion_t **champions, int start, int j)
{
    if (champions[j]->pc + champions[j]->prog_size > MEM_SIZE) {
        if (start >= champions[j]->pc && start <= MEM_SIZE)
            return 84;
        else if (start >= 0 && start <=
(champions[j]->pc + champions[j]->prog_size - MEM_SIZE))
            return 84;
    }
    else if (start >= champions[j]->pc && start <=
(champions[j]->pc + champions[j]->prog_size))
        return 84;
    return 0;
}

static int overlap_checker_loop(champion_t **champions, int start, int i)
{
    for (int j = 0; champions[j]; j++) {
        if (j == i)
            continue;
        if (overlap_conditions(champions, start, j) == 84)
            return 84;
    }
    return 0;
}

int check_overlap(champion_t **champions)
{
    int start = 0;

    for (int i = 0; champions[i]; i++) {
        start = champions[i]->pc;
        if (overlap_checker_loop(champions, start, i) == 84)
            return 84;
    }
    return 0;
}