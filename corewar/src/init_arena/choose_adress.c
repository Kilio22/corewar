/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** choose_adress
*/

#include "champions.h"
#include "corewar.h"

static int count_choosen_adresses(champion_t **champions)
{
    int nb_choosen = 0;

    for (int i = 0; champions[i]; i++)
        if (champions[i]->pc != -1)
            nb_choosen++;
    return nb_choosen;
}

static size_t count_bytecodes(champion_t **champions)
{
    size_t nb_bytes = 0;

    for (int i = 0; champions[i]; i++)
        nb_bytes += champions[i]->prog_size;
    return nb_bytes;
}

static int fill_empty(champion_t **champions)
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

static int fill_one_choose(champion_t **champions)
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

static void find_biggest_block(champion_t **champions, int biggest[2])
{
    int end = 0;
    int start = 0;

    sort_champions(champions, 1);
    for (; champions[start]->pc == -1; start++);
    for (int i = start; champions[i + 1]; i++) {
        end = champions[i]->pc + champions[i]->prog_size;
        if (end + champions[i + 1]->pc > biggest[1]) {
            biggest[1] = end + champions[i + 1]->pc;
            biggest[0] = end;
        }
    }
    for (; champions[start + 1]; start++);
    end = champions[start]->pc + champions[start]->prog_size;
    for (start = 0; champions[start]->pc == -1; start++);
    if ((MEM_SIZE - end + champions[start]->pc) > biggest[1]) {
        biggest[1] = MEM_SIZE - end + champions[start]->pc;
        biggest[0] = end;
    }
}

static void find_lowest_block(champion_t **champions, int biggest[2])
{
    int end = 0;
    int start = 0;

    sort_champions(champions, 1);
    for (; champions[start]->pc == -1; start++);
    end = champions[start]->pc + champions[start]->prog_size;
    biggest[1] = end + champions[start + 1]->pc;
    biggest[0] = end;
    for (int i = start; champions[i + 1]; i++) {
        end = champions[i]->pc + champions[i]->prog_size;
        if (end + champions[i + 1]->pc < biggest[1]) {
            biggest[1] = end + champions[i + 1]->pc;
            biggest[0] = end;
        }
    }
    for (; champions[start + 1]; start++);
    end = champions[start]->pc + champions[start]->prog_size;
    for (start = 0; champions[start]->pc == -1; start++);
    if ((MEM_SIZE - end + champions[start]->pc) < biggest[1]) {
        biggest[1] = MEM_SIZE - end + champions[start]->pc;
        biggest[0] = end;
    }
}

static int fill_multiple_choose(champion_t **champions)
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

static int fill_two_v_two(champion_t **champions)
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
        offset = (biggest_block[1] - LEN_CHAMP(2) + LEN_CHAMP(1)) / 2;
        CHAMP_PC(3) = biggest_block[0];
        CHAMP_PC(4) = CHAMP_PC(1) + offset;
    } else {
        CHAMP_PC(3) = biggest_block[0] +
((biggest_block[1] - LEN_CHAMP(1)) / 2);
        biggest_block[0] = 0;
        biggest_block[1] = 0;
        find_biggest_block(champions, biggest_block);
        CHAMP_PC(4) = biggest_block[0] +
((biggest_block[1] - LEN_CHAMP(2)) / 2);
    }
    return 0;
}

int choose_adresses(champion_t **champions)
{
    int nb_choosen = count_choosen_adresses(champions);

    sort_champions(champions, 0);
    if (nb_choosen == 0)
        return fill_empty(champions);
    if (nb_choosen == 1)
        return fill_one_choose(champions);
    if (my_arraylen((void **)champions) - nb_choosen == 1)
        return fill_multiple_choose(champions);
    if (my_arraylen((void **)champions) - nb_choosen == 2)
        return fill_two_v_two(champions);
    return 0;
}