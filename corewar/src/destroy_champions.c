/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** destroy_champions
*/

#include <stdlib.h>
#include "corewar.h"

void destroy_champions(champion_t **champions)
{
    while (*champions)
        free(*champions++);
}
