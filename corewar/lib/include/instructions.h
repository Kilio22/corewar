/*
** EPITECH PROJECT, 2019
** instructions.h
** File description:
** header of instruction part
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "op.h"

#define ARG_TYPE(n) (((desc << n * 2) & 0b11000000) >> 6)
#define GET_VAL(n) get_val(champ, core->arena, ARG_TYPE(n), args[n])

enum instruction_types {
    REG = 1,
    DIR,
    IDR
};

/* tools/ */
void refresh_carry(champion_t *champ, int value);
int get_val(champion_t *champ, char *arena, code_t desc, int val);
int get_long_val(champion_t *champ, char *arena, code_t desc, int val);
int is_reg(code_t desc, int *args, int nb_arg);
int get_first_two_bytes(int val);;

#define UNU __attribute__((unused))
int inst_live(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_ld(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_st(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_add(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_sub(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_and(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_or(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_xor(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_zjmp(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_ldi(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_sti(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_fork(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_lld(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_lldi(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_lfork(champion_t *champ, core_t *core, code_t desc, int *args);
int inst_aff(champion_t *champ, core_t *core, code_t desc, int *args);

#endif
