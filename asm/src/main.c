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
    for (int i = 0; i < ID_NUMBER - 1; i++)
        printf("|%s|\n", token_tab[i].delimit);
    file = get_file(argv[1], &header);
    if (!file)
        return 84;
    printf("%s\n", header.prog_name);
    printf("%s\n", header.comment);
    my_free_fields(file);
    return 0;
}
