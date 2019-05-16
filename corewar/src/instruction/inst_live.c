/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_live
*/

#include "corewar.h"

int inst_live(champion_t *c, core_t *core UNU, code_t desc UNU, int *args)
{
    static int call_count = 0;
    static int cycles_to_die = CYCLE_TO_DIE;

    ++call_count;
    if (args[0] < 1 || args[0] > 4)
        return 0;
    my_printf("The player %d(%s) is alive.\n", c->prog_id, c->prog_name);
    if (call_count >= NBR_LIVE) {
        cycles_to_die -= CYCLE_DELTA;
        call_count = 0;
    }
    set_champion_live(args[0] - 1, cycles_to_die);
    return 0;
}
