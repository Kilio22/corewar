/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** destroy_parsing
*/

#include <stdlib.h>
#include "corewar.h"

void destroy_args(parsing_t *parsing)
{
    for (int i = 0; parsing->params[i]; i++) {
        free(parsing->params[i]->fp);
        free(parsing->params[i]);
    }
    free(parsing->params);
}