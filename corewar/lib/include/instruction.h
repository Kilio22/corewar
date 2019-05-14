/*
** EPITECH PROJECT, 2019
** instruction.h
** File description:
** header of instruction part
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#define REG 1
#define DIR 2
#define IDR 3

/* inst_ld.c */

int inst_ld(champion_t *champ, char *arena, char desc, int *args);

/* inst_st.c */

int inst_st(champion_t *champ, char *arena, char desc, int *args);

/* inst_add.c */

int inst_add(champion_t *champ, char *arena, char desc, int *args);

#endif
