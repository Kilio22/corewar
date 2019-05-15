/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** op
*/

#include "corewar.h"

int debug(champion_t *champ, core_t *core, code_t desc, int *args)
{
    code_t tmp = desc;
    int j = 0;

    (void) core;
    printf("Champion %s[%d] called :", champ->prog_name, champ->prog_id);
    if (desc != 0) {
        printf(" %X[", desc);
        for (int i = 0; i < 8; i++) {
            printf("%d", (desc & 0b10000000) >> 7);
            desc <<= 1;
        }
        printf("]");
        while (tmp & 0b11000000) {
            printf(" %X", args[j++]);
            tmp <<= 2;
        }
    } else
        printf(" %X", args[0]);
    puts("");
    return 0;
}

const op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, debug},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, debug},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, debug},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, debug},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, debug},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, debug},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, debug},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, debug},
    {"zjmp", 1, {T_DIR}, 9, 20, debug},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, debug},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, debug},
    {"fork", 1, {T_DIR}, 12, 800, debug},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, debug},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, debug},
    {"lfork", 1, {T_DIR}, 15, 1000, debug},
    {"aff", 1, {T_REG}, 16, 2, debug},
    {0, 0, {0}, 0, 0, 0}
};
