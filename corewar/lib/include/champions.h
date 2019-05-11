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
    char *start_ptr;
    int prog_size;
    int reg[REG_NUMBER];
    int pc;
    int carry;
} chamption_t;

typedef struct champion_params {
    char *fp;
    int nb;
    int adress;
} champion_params_t;

typedef struct parsing {
    int dump;
    int nb_used[4];
    champion_params_t **params;
} parsing_t;

#endif /* !CHAMPIONS_H_ */
