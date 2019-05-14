/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_live
*/

#include "corewar.h"

int inst_live(champion_t *champ, char *arena, code_t desc, int *args)
{
    static int nb_times = 0;
    static int cycles_to_die = CYCLE_TO_DIE;

    if (args[0] < 1 || args[0] > 4)
        return 0;
    my_printf("Le joueur %d (%s) est en vie.\n",
champ->prog_id, champ->prog_name);
    ++nb_times;
    if (nb_times >= NBR_LIVE) {
        cycles_to_die -= CYCLE_DELTA;
        nb_times = 0;
    }
    set_champion_live(args[0], cycles_to_die);
    return 0;
}