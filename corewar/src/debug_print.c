/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** debug_print
*/

#include "corewar.h"

void print_params(parsing_t *parsing)
{
    for (int i = 0; parsing->params[i]; i++) {
        my_printf("------NEW-----\n");
        my_printf("Fp: %s\n", parsing->params[i]->fp);
        my_printf("Adress: %d\n", parsing->params[i]->adress);
        my_printf("Nb champ: %d\n", parsing->params[i]->nb);
    }
}

void print_champions(champion_t **champions)
{
    for (int i = 0; champions[i]; i++) {
        my_printf("------NEW------\n");
        my_printf("Name = %s\n", champions[i]->prog_name);
        my_printf("Id = %d\n", champions[i]->prog_id);
        my_printf("Adress = %d\n", champions[i]->pc);
        my_printf("Size = %d\n", champions[i]->prog_size);
    }
}