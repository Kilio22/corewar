/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar_loop
*/

#include <unistd.h>
#include "corewar.h"

int loop_corewar(champion_t **champions, int dump)
{
    char *arena = create_arena(champions);

    if (!arena)
        return 84;
    while (my_arraylen((void **) champions) > 1) {
        if (dump != -1 && !dump--) {
            dump_arena(arena);
            break;
        }
    }
    return 0;
}
