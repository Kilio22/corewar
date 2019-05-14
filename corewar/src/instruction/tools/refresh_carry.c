/*
** EPITECH PROJECT, 2019
** carry.c
** File description:
** handle carry
*/

#include "corewar.h"

void refresh_carry(champion_t *champ, int value)
{
    if (value == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
}
