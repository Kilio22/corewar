/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** utlis
*/

#include <stdlib.h>
#include "corewar.h"

int check_flag(char const *str)
{
    for (int i = 0; i < 3; i++) {
        if (!my_strcmp(str, flags[i]))
            return i;
    }
    return -1;
}

champion_t **realloc_champions(champion_t **champions, champion_t *new)
{
    size_t len = my_arraylen((void **) champions) + 2;
    champion_t **new_arr = malloc(sizeof(champion_t *) * len);
    size_t i = 0;

    if (!new_arr)
        return NULL;
    for (; champions[i]; i++)
        new_arr[i] = champions[i];
    new_arr[i] = new;
    new_arr[++i] = NULL;
    free(champions);
    return new_arr;
}

champion_params_t **realloc_params(champion_params_t **old)
{
    champion_params_t **new = malloc(sizeof(champion_params_t *) *
(my_arraylen((void **)old) + 2));
    int i = 0;

    if (!new)
        return NULL;
    for (; old[i]; i++)
        new[i] = old[i];
    new[i] = malloc(sizeof(champion_params_t));
    if (!new[i])
        return NULL;
    new[i]->fp = NULL;
    new[i]->nb = -1;
    new[i]->adress = -1;
    new[++i] = NULL;
    free(old);
    return new;
}