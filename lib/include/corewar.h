/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_string.h"
#include "my_stdio.h"
#include "my.h"

#define LEN_COMMS 9
#define COMMS ".comment "

extern const char *valid_char;

char *get_line(FILE *f_stream);

#endif /* !COREWAR_H_ */
