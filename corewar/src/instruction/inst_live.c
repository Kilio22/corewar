/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_live
*/

#include "corewar.h"

static int find_champion_index(core_t *core, int nb)
{
    size_t i = 0;

    for (; core->champions[i]; i++)
        if (core->champions[i]->prog_id == nb &&
core->champions[i]->forked == false)
            return i;
    return -1;
}

int inst_live(champion_t *c UNU, core_t *core, code_t desc UNU, int *args)
{
    // debug(c, core, desc, args);
    static int call_count = 0;
    static int cycles_to_die = CYCLE_TO_DIE;
    int index;

    ++call_count;
    if (args[0] < 1 || args[0] > 4)
        return 0;
    index = find_champion_index(core, args[0]);
    if (index != -1 && get_champion_live(args[0]) > 0)
        my_printf("Le joueur %d (%s) est en vie.\n",
core->champions[index]->prog_id, core->champions[index]->prog_name);
    if (call_count >= NBR_LIVE) {
        cycles_to_die -= CYCLE_DELTA;
        call_count = 0;
    }
    if (index != -1 && get_champion_live(args[0]) > 0)
        set_champion_live(args[0], cycles_to_die);
    return 0;
}
