/*
** EPITECH PROJECT, 2019
** instructions.h
** File description:
** header of instruction part
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#define ARG_TYPE(n) ((desc << n * 2) & 0b11000000) >> 6))
#define MASK(n) ARG_TYPE(n), args[n]

enum instruction_types {
    REG = 1,
    DIR,
    IDR
};

void refresh_carry(champion_t *champ, int value);
int get_val(champion_t *champ, char *arena, code_t desc, int val);
int get_long_val(champion_t *champ, char *arena, code_t desc, int val);

/* inst_ld.c */
int inst_ld(champion_t *champ, char *arena, char desc, int *args);

/* inst_st.c */
int inst_st(champion_t *champ, char *arena, char desc, int *args);

/* inst_add.c */
int inst_add(champion_t *champ, char *arena, char desc, int *args);

/* inst_sub.c */
int inst_sub(champion_t *champ, char *arena, char desc, int *args);

/* inst_and.c */
int inst_and(champion_t *champ, char *arena, char desc, int *args);

#endif
