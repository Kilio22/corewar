/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** main
*/

#include <stdlib.h>
#include "corewar.h"

static int corewar_main(int ac, char const *argv[])
{
    parsing_t parsing;

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
