/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** manage_parsing_fcts
*/

#include <stdlib.h>
#include "corewar.h"

int add_champ(char const *fp, parsing_t *parsing, int *current)
{
    if (!parsing->params[*current])
        parsing->params = realloc_params(parsing->params);
    if (!parsing->params)
        return -1;
    parsing->params[*current]->fp = my_strdup(fp);
    if (!parsing->params[*current]->fp)
        return -1;
    (*current)++;
    return 0;
}

int manage_dump(size_t *i, char const **tab, parsing_t *parsing, int *current)
{
    (void)current;
    if (!tab[(*i) + 1])
        return -1;
    if (!my_str_isnum(tab[(*i) + 1], 0))
        return -1;
    if (parsing->dump != -1)
        return -1;
    parsing->dump = my_atoi(tab[(*i) + 1]);
    (*i)++;
    return 0;
}

int manage_nb(size_t *i, char const **tab, parsing_t *parsing, int *current)
{
    if (!parsing->params[*current])
        parsing->params = realloc_params(parsing->params);
    if (!parsing->params)
        return -1;
    if (!tab[(*i) + 1])
        return -1;
    if (parsing->params[*current]->nb != -1)
        return -1;
    if (!my_str_isnum(tab[(*i) + 1], 0))
        return -1;
    if (my_atoi(tab[(*i) + 1]) <= 0 || my_atoi(tab[(*i) + 1]) > 4)
        return -1;
    if (parsing->nb_used[my_atoi(tab[(*i) + 1]) - 1] != -1)
        return -1;
    else
        parsing->nb_used[my_atoi(tab[(*i) + 1]) - 1] = 1;
    parsing->params[*current]->nb = my_atoi(tab[(*i) + 1]);
    (*i)++;
    return 0;
}

int manage_adress(size_t *i, char const **tab, parsing_t *parsing, int *current)
{
    if (!parsing->params[*current])
        parsing->params = realloc_params(parsing->params);
    if (!parsing->params)
        return -1;
    if (!tab[(*i) + 1])
        return -1;
    if (!my_str_isnum(tab[(*i) + 1], 0))
        return -1;
    if (parsing->params[*current]->adress != -1)
        return -1;
    parsing->params[*current]->adress = my_atoi(tab[(*i) + 1]);
    (*i)++;
    return 0;
}