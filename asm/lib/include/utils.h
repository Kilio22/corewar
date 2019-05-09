/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>

char *get_line(FILE *f_stream);
char *my_strcat_nofree(const char *left, const char *right);
char *skip_whitespaces(char *line);
char *delete_end_whitespaces(char *line);
size_t my_quote_len(char *line);
int is_empty_line(const char *line);
char *delete_end_whitespaces(char *line);
int check_index_need(int index);
char *cut_string(char **src, size_t index);
char *slice_string(char **src, size_t index);
struct instruction *get_last_inst_node(struct instruction *head);
struct label *get_last_label_node(struct label *head);
struct instruction *shift_inst(struct instruction *inst);
bool op_needs_args(int index);

#define OP_NBR_ARGS(i) (op_tab[i].nbr_args)

#endif /* !UTILS_H_ */
