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
#include "instructions.h"

typedef struct champion champion_t;

char *create_arena(champion_t **champions);
int loop_corewar(champion_t **champions, int dump);
void dump_arena(char *arena);

#endif /* !COREWAR_H_ */
