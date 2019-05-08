/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include "insctruction.h"

typedef struct token {
    char *delimit;
    short id;
    short type;
} token_t;

extern token_t token_tab[ID_NUMBER];

#define GET_TOKEN_ID(n) (token_tab[n].id)
#define GET_TOKEN_TYPE(n) (token_tab[n].type)
#define IS_SEP(n) (GET_TOKEN_TYPE(n) == D_SEPARATOR)

#endif /* !PARSER_H_ */
