/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** fill_adresses
*/

#include "corewar.h"

int fill_empty(champion_t **champions)
{
    size_t nb_bytes_total = count_bytecodes(champions);
    size_t separation = 0;

    if (nb_bytes_total > MEM_SIZE)
        return 84;
    separation = (MEM_SIZE - nb_bytes_total) / my_arraylen((void **)champions);
    champions[0]->pc = 0;
    for (int i = 1; champions[i]; i++) {
        champions[i]->pc = champions[i - 1]->pc +
champions[i - 1]->prog_size + separation;
    }
    return 0;
}

int fill_one_choose(champion_t **champions)
{
    size_t nb_bytes_total = count_bytecodes(champions);
    size_t separation = 0;
    int i = 0;

    if (nb_bytes_total > MEM_SIZE)
        return 84;
    sort_champions(champions, 1);
    for (; champions[i]->pc == -1; i++);
    separation = (MEM_SIZE - nb_bytes_total) / my_arraylen((void **)champions);
    for (i--; i >= 0; i--) {
        champions[i]->pc = champions[i + 1]->pc +
champions[i + 1]->prog_size + separation;
    }
    return 0;
}

int fill_multiple_choose(champion_t **champions)
{
    size_t nb_bytes_total = count_bytecodes(champions);
    int biggest_block[2] = {0, 0};

    if (nb_bytes_total > MEM_SIZE)
        return 84;
    find_biggest_block(champions, biggest_block);
    champions[0]->pc = biggest_block[0] +
((biggest_block[1] - champions[0]->prog_size) / 2);
    return 0;
}

static void handle_two_separate_blocks(int biggest_block[2],
champion_t **champions)
{
    CHAMP_PC(3) = biggest_block[0] +
((biggest_block[1] - LEN_CHAMP(3)) / 2);
        biggest_block[0] = 0;
        biggest_block[1] = 0;
        find_biggest_block(champions, biggest_block);
        CHAMP_PC(4) = biggest_block[0] +
((biggest_block[1] - LEN_CHAMP(4)) / 2);
}

int fill_two_v_two(champion_t **champions)
{
    size_t nb_bytes_total = count_bytecodes(champions);
    int biggest_block[2] = {0, 0};
    int lowest_block[2] = {0, 0};
    int offset = 0;
    int new = 0;

    if (nb_bytes_total > MEM_SIZE)
        return 84;
    find_biggest_block(champions, biggest_block);
    find_lowest_block(champions, lowest_block);
    new = biggest_block[1] - LEN_CHAMP(1);
    if (new >= lowest_block[1]) {
        offset = (biggest_block[1] - (LEN_CHAMP(2) + LEN_CHAMP(1))) / 3;
        CHAMP_PC(3) = biggest_block[0] + offset;
        CHAMP_PC(4) = CHAMP_PC(3) + LEN_CHAMP(3) + offset;
    } else
        handle_two_separate_blocks(biggest_block, champions);
    return 0;
}