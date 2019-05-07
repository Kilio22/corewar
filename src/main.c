/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "op.h"
#include "corewar.h"
#include "asm.h"

int main(int argc, char const *argv[])
{
    char **file = NULL;
    header_t header;

    if (argc != 2)
        return 84;
    file = get_file(argv[1]);
    if (!file)
        return 84;
    if (get_header(file, &header))
        return 84;
    printf("%s\n", header.prog_name);
    printf("%s\n", header.comment);
    return 0;
}
