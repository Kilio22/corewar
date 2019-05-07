/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_name
*/

#include "asm.h"
#include "op.h"
#include "my_string.h"
#include "corewar.h"

int is_valid_quots(char *line)
{
    int nb_quots = 0;
    size_t index = -1;
    size_t i = 0;
    size_t j = 0;

    for (i = 0; line[i]; i++) {
        if (my_strchr("\"", line[i]))
            nb_quots++;
        if (nb_quots == 2 && my_strchr("\"", line[i]))
            index = i;
    }
    for (j = index + 1; line[j]
&& (line[j] == ' ' || line[j] == '\t'); j++);
    if (nb_quots != 2 || line[j] != '\0')
        return -1;
    return 0;
}

int get_name(char **file, header_t *header)
{
    int nb_name = 0;
    size_t j = 0;
    size_t d = 0;

    for (size_t i = 0; file[i]; i++) {
        if (my_strncmp(file[i], ".name ", 6) == 0)
            nb_name++;
        if (my_strncmp(file[i], ".name ", 6) == 0 && i != 0)
            return -1;
    }
    if (nb_name != 1 || my_strlen(file[0]) > PROG_NAME_LENGTH)
        return -1;
    for (j = 6; file[0][j] && my_strchr((char *)valid_char, file[0][j]); j++);
    if (is_valid_quots(&file[0][j]))
        return -1;
    j++;
    for (; file[0][j] != '"'; j++, d++)
        header->prog_name[d] = file[0][j];
    header->prog_name[d] = '\0';
    return 0;
}