/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parsing
*/

#include <stdlib.h>
#include "corewar.h"

static int manage_params(char const *argv[], parsing_t *parsing,
size_t *i, int *current_champ)
{
    int n_val = 0;

    if (argv[*i][0] == '-') {
        n_val = check_flag(argv[*i]);
        if (n_val == -1)
            return -1;
        if (tab_ftcs[n_val](i, argv, parsing, current_champ) == -1)
            return -1;
    } else {
        n_val = add_champ(argv[*i], parsing, current_champ);
        if (n_val == -1)
            return -1;
    }
    return 0;
}

static int init_parsing(parsing_t *parsing)
{
    parsing->dump = -1;
    parsing->params = malloc(sizeof(champion_params_t));
    if (!parsing->params)
        return -1;
    parsing->params[0] = NULL;
    for (int i = 0; i < 4; i++)
        parsing->nb_used[i] = -1;
    return 0;
}

static int find_nb_champ(parsing_t *parsing)
{
    for (int i = 0; i < 4; i++)
        if (parsing->nb_used[i] == -1) {
            parsing->nb_used[i] = 1;
            return i + 1;
        }
    return -1;
}

int parse_args(int ac, char const *argv[], parsing_t *parsing)
{
    int current_champ = 0;

    if (init_parsing(parsing) == -1)
        return 84;
    if (ac < 2)
        return -1;
    for (size_t i = 1; argv[i]; i++)
        if (manage_params(argv, parsing, &i, &current_champ) == -1)
            return -1;
    if (my_arraylen((void **)parsing->params) > 4
|| my_arraylen((void **)parsing->params) < 2)
        return -1;
    for (int i = 0; parsing->params[i]; i++) {
        if (parsing->params[i]->nb == -1)
            parsing->params[i]->nb = find_nb_champ(parsing);
        if (!parsing->params[i]->fp)
            return -1;
    }
    return 0;
}