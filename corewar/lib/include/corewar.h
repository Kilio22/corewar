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

typedef struct core_s {
    champion_t **champions;
    char *arena;
} core_t;

void print_params(parsing_t *parsing);
void print_champions(champion_t **champions);
char *create_arena(champion_t **champions);
int loop_corewar(core_t *core, int dump);
void dump_arena(char *arena);
void display_winning_champions(champion_t **champions);
bool is_game_ended(champion_t **champions);
void update_champions_live_status(champion_t **champions);
int check_param_bytecode(int op_idx, char args);
int find_type(char args);
int count_inst_bytes(code_t code, int op_idx);
int get_arg_length(char type, int index);
int read_arg(char *arena, int offset, int n);
void write_arg(char *arena, int offset, int val);

int debug(champion_t *champ, core_t *core, code_t desc, int *args);

#endif /* !COREWAR_H_ */
