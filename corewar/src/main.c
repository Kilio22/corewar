/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** main
*/

#include <stdlib.h>
#include "corewar.h"

static void print_params(parsing_t *parsing)
{
    for (int i = 0; parsing->params[i]; i++) {
        my_printf("------NEW-----\n");
        my_printf("Fp: %s\n", parsing->params[i]->fp);
        my_printf("Adress: %d\n", parsing->params[i]->adress);
        my_printf("Nb champ: %d\n", parsing->params[i]->nb);
    }
}

static int corewar_main(int ac, char const *argv[])
{
    parsing_t parsing;
    champion_t *champions[MAX_CHAMPIONS + 1] = {0, 0, 0, 0, 0};

    if (parse_args(ac, argv, &parsing) == -1) {
        destroy_args(&parsing);
        return 84;
    }
    destroy_args(&parsing);
    return 0;
}

int main(int argc, char const *argv[])
{
    return corewar_main(argc, argv);
}
