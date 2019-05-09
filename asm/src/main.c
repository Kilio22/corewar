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
    struct instruction **list;

    if (argc != 2)
        return 84;
    file = get_file(argv[1], &header);
    if (!file)
        return 84;
    printf("%s\n", header.prog_name);
    printf("%s\n", header.comment);
    list = load_instructions(file);
    if (!list) {
        my_free_fields(file);
        return 84;
    }
    for (int i = 0; list[i]; i++) {
        struct instruction *tmp = list[i];
        while (tmp) {
            printf("%s %d %d\n", tmp->instruction, tmp->id, tmp->type);
            tmp = tmp->next;
        }
    }
    destroy_instruction_list(list);
    my_free_fields(file);
    return 0;
}
