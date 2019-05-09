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
    struct instruction **list = NULL;
    struct instruction **save = NULL;

    if (argc != 2)
        return 84;
    file = get_file(argv[1], &header);
    if (!file)
        return 84;
    printf("%s\n", header.prog_name);
    printf("%s\n", header.comment);
    list = load_instructions(file);
    save = list;
    /* for (int i = 0; list[i]; i++) {
        while (list[i]) {
            printf("%s %d %d\n", list[i]->instruction, list[i]->id, list[i]->type);
            list[i] = list[i]->next;
        }
    } */
    if (check_syntax_loop(save) == 84)
        return 84;
    my_free_fields(file);
    return 0;
}
