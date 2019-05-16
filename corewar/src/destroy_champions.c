/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** destroy_champions
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"

void destroy_champion(champion_t *champ)
{
    if (!champ->forked)
        close(champ->fd);
    free(champ);
}

void delete_champion_id(champion_t **champions, int id)
{
    champion_t *tmp = NULL;

    for (int i = 0; champions[i]; i++) {
        if (champions[i]->prog_id != id)
            continue;
        for (int j = i; champions[j + 1]; j++) {
            tmp = champions[j + 1];
            champions[j + 1] = champions[j];
            champions[j] = tmp;
        }
        destroy_champion(champions[my_arraylen((void **) champions) - 1]);
        champions[my_arraylen((void **) champions) - 1] = NULL;
        i--;
    }
}

void destroy_champions(champion_t **champions)
{
    while (*champions)
        destroy_champion(*champions++);
}
