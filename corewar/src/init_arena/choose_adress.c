/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** choose_adress
*/

#include "champions.h"
#include "corewar.h"

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