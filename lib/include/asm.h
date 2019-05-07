/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#include "corewar.h"
#include "op.h"

int launch_asm(char *filepath);

//get_file
char **get_file(const char *fp);

//get_header
int get_header(char **file, header_t *header);
int get_name(char **file, header_t *header);
int get_comments(char **file, header_t *header);
int is_valid_quots(char *line);

#endif /* !ASM_H_ */
