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

parsing_functions_t tab_ftcs[] = {
    manage_dump, manage_nb, manage_adress
};
