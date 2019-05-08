/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parser_globals
*/

#include <stdlib.h>
#include "parser.h"
#include "op.h"
#include "my_string.h"

token_t token_tab[ID_NUMBER] = {
    {" ", ID_SPACE, D_NORMAL},
    {"\t", ID_TAB, D_NORMAL},
    {",", ID_SEPARATOR, D_SEPARATOR},
    {":", ID_LABEL, D_GET},
    {"%", ID_DIRECT, D_GET},
    {"#", ID_COMMENT, D_COMMENT},
    {NULL, ID_NOTHING, D_WITHOUT}
};

int find_token_index(char *ptr)
{
    for (int i = 0; token_tab[i].delim; i++)
        if (!my_strncmp(ptr, token_tab[i].delim, my_strlen(token_tab[i].delim)))
            return i;
    return -1;
}
