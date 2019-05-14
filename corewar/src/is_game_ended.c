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

    if (!*champions) {
        my_printf("Tous les champions sont morts...\n");
        return;
    }
    nb = get_champion_live(0);
    for (int i = 1; champions[i]; i++) {
        if (champions[i]->cycles_until_death == -1 ||
get_champion_live(champions[i]->prog_id) > nb)
            nb = get_champion_live(champions[i]->prog_id);
    }
    for (int i = 0; champions[i]; i++) {
        if (champions[i]->cycles_until_death == -1 ||
get_champion_live(champions[i]->prog_id) == nb)
            my_printf("Le joueur %d (%s) a gagné.\n",
champions[i]->prog_id, champions[i]->prog_name);
    }
}

bool is_game_ended(champion_t **champions)
{
    int nb_alive = 0;

    for (int i = 0; champions[i]; i++) {
        if (champions[i]->cycles_until_death == -1 ||
get_champion_live(champions[i]->prog_id) > 0)
            nb_alive++;
    }
    if (nb_alive <= 1)
        return true;
    return false;
}

void update_champions_live_status(champion_t **champions)
{
    for (int i = 0; champions[i]; i++) {
        if (champions[i]->cycles_until_death == -1 ||
get_champion_live(champions[i]->prog_id) > 0)
            continue;
        delete_champion_id(champions, champions[i]->prog_id);
        i = -1;
    }
}