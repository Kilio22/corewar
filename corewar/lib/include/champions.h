/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** champions
*/

#ifndef CHAMPIONS_H_
#define CHAMPIONS_H_

#include "op.h"

#define MAX_CHAMPIONS 4

typedef struct champion {
    char prog_name[PROG_NAME_LENGTH + 1];
    char *beginning;
    int prog_size;
    int reg[REG_NUMBER];
    int pc;
    int carry;
    int fd;
} champion_t;

#endif /* !CHAMPIONS_H_ */
