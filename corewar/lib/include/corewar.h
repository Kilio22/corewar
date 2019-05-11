/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdbool.h>
#include <stdio.h>
#include "op.h"
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"
#include "champions.h"

champion_params_t **realloc_params(champion_params_t **old);
int check_flag(char const *str);
int manage_adress(size_t *i, char const **tab, parsing_t *parsing, int *current);
int manage_nb(size_t *i, char const **tab, parsing_t *parsing, int *current);
int manage_dump(size_t *i, char const **tab, parsing_t *parsing, int *current);
int add_champ(char const *fp, parsing_t *parsing, int *current);
int parse_args(int ac, char const *argv[], parsing_t *parsing);
void destroy_args(parsing_t *parsing);

extern const char *flags[];
extern int (* const tab_ftcs[])(size_t *, char const **argv, parsing_t *, int *);

#endif /* !COREWAR_H_ */
