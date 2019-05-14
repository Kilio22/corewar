/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** is_game_ended
*/

#include "corewar.h"

void display_winning_champions(champion_t **champions)
{
    int nb = 0;

    if (!champions[0]) {
        my_printf("No one won\n");
        return;
    }
    nb = champions[0]->cycles_until_death;
    for (int i = 1; champions[i]; i++) {
        if (champions[i]->cycles_until_death > nb)
            nb = champions[i]->cycles_until_death;
    }
    for (int i = 0; champions[i]; i++) {
        if (champions[i]->cycles_until_death == nb)
            my_printf("Le joueur %d (%s) a gagné.\n",
champions[i]->prog_id, champions[i]->prog_name);
    }
}

bool is_game_ended(champion_t **champions)
{
    int nb_alive = 0;

    for (int i = 0; champions[i]; i++) {
        if (champions[i]->cycles_until_death > 0)
            nb_alive++;
    }
    if (nb_alive <= 1)
        return true;
    return false;
}

void update_champions_live_status(champion_t **champions)
{
    for (int i = 0; champions[i]; i++) {
        if (champions[i]->cycles_until_death > 0)
            continue;
        printf("Deleted champion %s[%d]\n", champions[i]->prog_name, champions[i]->prog_id);
        delete_champion_id(champions, champions[i]->prog_id);
    }
}