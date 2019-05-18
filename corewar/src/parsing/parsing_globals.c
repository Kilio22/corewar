/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parsing_globals
*/

#include "corewar.h"

const char *flags[] = {
    "-dump",
    "-n",
    "-a"
};

int (* const tab_ftcs[])(size_t *, char const **, parsing_t *, int *) = {
    manage_dump, manage_nb, manage_adress
};
