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
}

static int init_corewar(champion_t **champions, parsing_t *parsing, int ac,
char const *av[])
{
    if (parse_args(ac, av, parsing) == -1) {
        destroy_corewar(champions, parsing);
        return 84;
    }
    print_params(parsing);
    if (init_champions(champions, parsing) ||
choose_adresses(champions) == 84) {
        destroy_corewar(champions, parsing);
        return 84;
    }
    sort_champions(champions, 0);
    print_champions(champions);
    if (check_overlap(champions) == 84) {
        destroy_corewar(champions, parsing);
        return 84;
    }
    return 0;
}

static int corewar_main(int ac, char const *argv[])
{
    parsing_t parsing;
    champion_t *champions[MAX_CHAMPIONS + 1] = {0, 0, 0, 0, 0};
    int n_return = 0;

    if (init_corewar(champions, &parsing, ac, argv) == 84)
        return 84;
    loop_corewar(champions, parsing.dump);
    destroy_champions(champions);
    destroy_args(&parsing);
    return n_return;
}

int main(int argc, char const *argv[])
{
    return corewar_main(argc, argv);
}
