
/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** create_champion_list
*/

#include "corewar.h"

int init_champions(champion_t **champions, parsing_t *rules)
{
    for (int i = 0; rules->params[i]; i++) {
        champions[i] = create_champion(rules->params[i]->fp);
        if (!champions[i])
            return 84;
        champions[i]->prog_id = rules->params[i]->nb;
        champions[i]->reg[0] = champions[i]->prog_id;
        champions[i]->pc = rules->params[i]->adress % MEM_SIZE;
    }
    return 0;
}
