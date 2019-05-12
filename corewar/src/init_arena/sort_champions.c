/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** sort_champions
*/

#include "corewar.h"

static int is_sorted_by_adress(champion_t **champions)
{
    for (int i = 0; champions[i + 1]; i++) {
        if (champions[i]->pc > champions[i + 1]->pc)
            return 0;
        else if (champions[i]->pc == -1 && champions[i + 1]->pc == -1
&& champions[i]->prog_id < champions[i + 1]->prog_id)
            return 0;
    }
    return 1;
}

static int is_sorted(champion_t **champions, int flag)
{
    if (flag == 1)
        return is_sorted_by_adress(champions);
    for (int i = 0; champions[i + 1]; i++) {
        if (champions[i]->prog_id > champions[i + 1]->prog_id)
            return 0;
    }
    return 1;
}

static void sorter_by_id(champion_t **champions)
{
    champion_t *tmp;

    for (int i = 0; champions[i + 1]; i++) {
        if (champions[i]->prog_id > champions[i + 1]->prog_id) {
            tmp = champions[i];
            champions[i] = champions[i + 1];
            champions[i + 1] = tmp;
        }
    }
}

static void sorter_by_adress(champion_t **champions)
{
    champion_t *tmp;

    for (int i = 0; champions[i + 1]; i++) {
        if (champions[i]->pc > champions[i + 1]->pc) {
            tmp = champions[i];
            champions[i] = champions[i + 1];
            champions[i + 1] = tmp;
        } else if (champions[i]->pc == -1 && champions[i + 1]->pc == -1
&& champions[i]->prog_id < champions[i + 1]->prog_id) {
            tmp = champions[i];
            champions[i] = champions[i + 1];
            champions[i + 1] = tmp;
        }
    }
}

void sort_champions(champion_t **champions, int flag)
{
    while (!is_sorted(champions, flag)) {
        if (flag == 0)
            sorter_by_id(champions);
        else
            sorter_by_adress(champions);
    }
}