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
    file = get_file(argv[1], &header);
    if (!file)
        return 84;
    printf("%s\n", header.prog_name);
    printf("%s\n", header.comment);
    struct instruction **list = load_instructions(file);
    for (int i = 0; list[i]; i++) {
        while (list[i]) {
            printf("%s %d %d\n", list[i]->instruction, list[i]->id, list[i]->type);
            list[i] = list[i]->next;
        }
    }
    my_free_fields(file);
    return 0;
}
