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
#include "parsing.h"
#include "champions.h"

typedef struct champion champion_t;

void print_params(parsing_t *parsing);
void print_champions(champion_t **champions);
char *create_arena(champion_t **champions);
int loop_corewar(champion_t **champions, int dump);
void dump_arena(char *arena);
void display_winning_champions(champion_t **champions);
bool is_game_ended(champion_t **champions);
void update_champions_live_status(champion_t **champions);

#endif /* !COREWAR_H_ */
