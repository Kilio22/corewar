/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** manage_champions_live
*/

#include "corewar.h"

int fetch_champions_life(int index, int flag)
{
    static int lives[MAX_CHAMPIONS] = {CYCLE_TO_DIE, CYCLE_TO_DIE,
CYCLE_TO_DIE, CYCLE_TO_DIE};

    if (flag == -2)
        return lives[index];
    if (flag != -1) {
        lives[index] = flag;
        return 0;
    }
    --lives[0];
    --lives[1];
    --lives[2];
    --lives[3];
    return 0;
}

int get_champion_live(int index)
{
    return fetch_champions_life(index, -2);
}

void set_champion_live(int index, int value)
{
    return fetch_champions_life(index, value);
}

void update_champions_live(void)
{
    fetch_champions_life(0, -1);
}