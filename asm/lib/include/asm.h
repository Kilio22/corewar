/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "utils.h"
#include "my_string.h"
#include "insctruction.h"
#include "parser.h"
#include "my.h"

int launch_asm(char *filepath);

//write_header
int write_header(const int fd, const header_t *header);

//get_file
char **get_file(const char *fp, header_t *header);

//get_header
int get_header(FILE *stream, header_t *header);

int compile_file(struct instruction **list, struct label *head, int fd);

//errors
int is_t_ind(struct instruction *instruction);
int is_t_dir(struct instruction *instruction);
int is_t_reg(struct instruction *instruction);
int check_type(struct instruction *instruction);
int check_comas(struct instruction *instruction, int nb);
int check_instruction_occurences(char *instruction);
int check_labels(struct instruction *instruction);
int check_if_labels_exist(struct instruction **list, struct label *head);

//count bytes
int count_instruction_bytes(struct instruction *inst);
char get_parameters_code(struct instruction *instruction, int index);
int get_parameter_size(struct instruction *inst, int index);

#endif /* !ASM_H_ */
