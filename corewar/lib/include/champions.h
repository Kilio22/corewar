/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** champions
*/

#ifndef CHAMPIONS_H_
#define CHAMPIONS_H_

#include "op.h"

typedef struct champion {
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_id;
    int prog_size;
    char *prog_start;
    int reg[REG_NUMBER];
    int cycles_until_death;
    int pc;
    int carry;
    int fd;
} champion_t;

champion_t *create_champion(const char *champ_path);
int init_champions(champion_t **champions, parsing_t *rules);
void destroy_champions(champion_t **champions);

#endif /* !CHAMPIONS_H_ */
