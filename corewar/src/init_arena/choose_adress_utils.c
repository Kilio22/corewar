/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** choose_adress_utils
*/

#include "corewar.h"

int count_choosen_adresses(champion_t **champions)
{
    int nb_choosen = 0;

    for (int i = 0; champions[i]; i++)
        if (champions[i]->pc != -1)
            nb_choosen++;
    return nb_choosen;
}

size_t count_bytecodes(champion_t **champions)
{
    size_t nb_bytes = 0;

    for (int i = 0; champions[i]; i++)
        nb_bytes += champions[i]->prog_size;
    return nb_bytes;
}

void find_biggest_block(champion_t **champions, int biggest[2])
{
    int end = 0;
    int start = 0;

    sort_champions(champions, 1);
    for (; champions[start]->pc == -1; start++);
    for (int i = start; champions[i + 1]; i++) {
        end = champions[i]->pc + champions[i]->prog_size;
        if (champions[i + 1]->pc - end > biggest[1]) {
            biggest[1] = champions[i + 1]->pc - end;
            biggest[0] = end;
        }
    }
    for (; champions[start + 1]; start++);
    end = champions[start]->pc + champions[start]->prog_size;
    for (start = 0; champions[start]->pc == -1; start++);
    end = end - MEM_SIZE;
    if (champions[start]->pc - end > biggest[1]) {
        biggest[1] = champions[start]->pc - end;
        biggest[0] = end + MEM_SIZE;
    }
}

static void check_last_block(champion_t **champions, int biggest[2],
int *start, int *end)
{
    for (; champions[(*start) + 1]; (*start)++);
    (*end) = champions[(*start)]->pc + champions[(*start)]->prog_size;
    for ((*start) = 0; champions[(*start)]->pc == -1; (*start)++);
    (*end) = (*end) - MEM_SIZE;
    if (champions[(*start)]->pc - (*end) < biggest[1]) {
        biggest[1] = champions[(*start)]->pc - (*end);
        biggest[0] = (*end) + MEM_SIZE;
    }
}

void find_lowest_block(champion_t **champions, int biggest[2])
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
        if (champions[i + 1]->pc - end < biggest[1]) {
            biggest[1] = champions[i + 1]->pc - end;
            biggest[0] = end;
        }
    }
    check_last_block(champions, biggest, &start, &end);
}