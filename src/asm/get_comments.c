/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_comments
*/

#include "op.h"
#include "my_string.h"
#include "asm.h"
#include "corewar.h"

int get_comments(char **file, header_t *header)
{
    int nb_comm = 0;
    size_t j = 0;
    size_t d = 0;

    for (size_t i = 0; file[i]; i++) {
        if (my_strncmp(file[i], COMMS, LEN_COMMS) == 0)
            nb_comm++;
        if (my_strncmp(file[i], COMMS, LEN_COMMS) == 0 && i != 1)
            return -1;
    }
    if (nb_comm != 1 || my_strlen(file[1]) > COMMENT_LENGTH)
        return -1;
    for (j = LEN_COMMS; file[1][j] && my_strchr((char *)valid_char, file[1][j]); j++);
    if (is_valid_quots(&file[1][j]))
        return -1;
    j++;
    for (; file[1][j] != '"'; j++, d++)
        header->comment[d] = file[1][j];
    header->comment[d] = '\0';
    return 0;
}