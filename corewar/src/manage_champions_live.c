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
        return lives[index - 1];
    if (flag != -1) {
        lives[index - 1] = flag;
        return 0;
    }
    lives[0] = lives[0] >= 0 ? lives[0] - 1 : -1;
    lives[1] = lives[1] >= 0 ? lives[1] - 1 : -1;
    lives[2] = lives[2] >= 0 ? lives[2] - 1 : -1;
    lives[3] = lives[3] >= 0 ? lives[3] - 1 : -1;
    // printf("%d %d %d %d\n", lives[0], lives[1], lives[2], lives[3]);
    return 0;
}

int get_champion_live(int index)
{
    return fetch_champions_life(index, -2);
}

void set_champion_live(int index, int value)
{
    fetch_champions_life(index, value);
}

void update_champions_live(void)
{
    fetch_champions_life(0, -1);
}