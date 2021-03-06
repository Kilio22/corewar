/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** main
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"

static void destroy_corewar(champion_t **champions, parsing_t *parsing)
{
    destroy_args(parsing);
    destroy_champions(champions);
    free(champions);
}

static int init_corewar(champion_t **champions, parsing_t *parsing, int ac,
char const *av[])
{
    if (parse_args(ac, av, parsing) == -1) {
        destroy_corewar(champions, parsing);
        return 84;
    }
    if (init_champions(champions, parsing) == 84 ||
choose_adresses(champions) == 84) {
        destroy_corewar(champions, parsing);
        return 84;
    }
    for (int i = 0; champions[i]; i++)
        champions[i]->pc %= MEM_SIZE;
    sort_champions(champions, 0);
    if (check_overlap(champions) == 84) {
        destroy_corewar(champions, parsing);
        return 84;
    }
    return 0;
}

static int corewar_main(int ac, char const *argv[], core_t *core)
{
    parsing_t parsing;
    int n_return = 0;

    parsing.params = NULL;
    for (size_t i = 0; i < MAX_CHAMPIONS; i++)
        core->champions[i] = NULL;
    if (init_corewar(core->champions, &parsing, ac, argv) == 84)
        return 84;
    if (loop_corewar(core, parsing.dump) == 84) {
        destroy_corewar(core->champions, &parsing);
        return 84;
    }
    destroy_corewar(core->champions, &parsing);
    return n_return;
}

int main(int argc, char const *argv[])
{
    core_t core;

    core.champions = malloc(sizeof(champion_t *) * (MAX_CHAMPIONS + 1));
    if (!core.champions)
        return 84;
    for (int i = 0; i < MAX_CHAMPIONS + 1; i++)
        core.champions[i] = NULL;
    return corewar_main(argc, argv, &core);
}
