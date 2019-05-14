/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** check_param_bytecode
*/

#include "corewar.h"

const char desc[3] = {0b01, 0b10, 0b11};
const char tab[3] = {T_REG, T_DIR, T_IND};

int find_type(char args)
{
    char code = args & 0b11;

    for (int i = 0; i < 3; i++) {
        if (code == desc[i])
            return tab[i];
    }
    return -1;
}

int check_param_bytecode(int op_idx, char args)
{
    int i = 4;
    char tmp = 0;

    for (; i > op_tab[op_idx].nbr_args; i--)
        args >>= 2;
    for (; i > 0; i--) {
        tmp = find_type(args);
        if (tmp == -1)
            return -1;
        if (!(tmp & op_tab[op_idx].type[i - 1]))
            return -1;
        args >>= 2;
    }
    return 0;
}
