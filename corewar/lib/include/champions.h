/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** champions
*/

#ifndef CHAMPIONS_H_
#define CHAMPIONS_H_

#include "corewar.h"
#include "op.h"

typedef struct champion {
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_id;
    int prog_size;
    int reg[REG_NUMBER];
    int cycles_until_death;
    int freeze;
    int pc;
    int carry;
    int fd;
} champion_t;

champion_t *create_champion(const char *champ_path);
int init_champions(champion_t **champions, parsing_t *rules);
void destroy_champion(champion_t *champ);
void destroy_champions(champion_t **champions);
void sort_champions(champion_t **champions, int flag);
int choose_adresses(champion_t **champions);
int check_overlap(champion_t **champions);
size_t count_bytecodes(champion_t **champions);
int count_choosen_adresses(champion_t **champions);
void find_lowest_block(champion_t **champions, int biggest[2]);
void find_biggest_block(champion_t **champions, int biggest[2]);
int fill_empty(champion_t **champions);
int fill_one_choose(champion_t **champions);
int fill_multiple_choose(champion_t **champions);
int fill_two_v_two(champion_t **champions);
void delete_champion_id(champion_t **champions, int id);
void update_champions_live(void);
int get_champion_live(int index);
int fetch_champions_life(int index, int flag);
void set_champion_live(int index, int value);
champion_t **realloc_champions(champion_t **champions, champion_t *new);

#define LEN_CHAMP(n) champions[my_arraylen((void **)champions) - n]->prog_size
#define CHAMP_PC(n) champions[my_arraylen((void **)champions) - n]->pc
#define PC champions[i]->pc

#endif /* !CHAMPIONS_H_ */
