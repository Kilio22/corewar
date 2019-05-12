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
    int n_return = 0;

    if (parse_args(ac, argv, &parsing) == -1) {
        destroy_args(&parsing);
        return 84;
    }
    print_params(&parsing);
    n_return = init_champions(champions, &parsing);
    if (!n_return)
        n_return = choose_adresses(champions);
    sort_champions(champions, 0);
    for (int i = 0; champions[i]; i++) {
        printf("------NEW------\n");
        printf("Name = %s\n", champions[i]->prog_name);
        printf("Id = %d\n", champions[i]->prog_id);
        printf("Adress = %d\n", champions[i]->pc);
        printf("Size = %d\n", champions[i]->prog_size);
    }
    destroy_champions(champions);
    destroy_args(&parsing);
    return n_return;
}

int main(int argc, char const *argv[])
{
    return corewar_main(argc, argv);
}
