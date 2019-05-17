/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** inst_fork
*/

#include <stdlib.h>
#include "corewar.h"

static champion_t *dup_champion(champion_t *origin)
{
    champion_t *new = malloc(sizeof(champion_t));

    if (!new)
        return NULL;
    my_strcpy(new->prog_name, origin->prog_name);
    new->prog_id = origin->prog_id;
    new->prog_size = origin->prog_size;
    for (int i = 0; i < REG_NUMBER; i++)
        new->reg[i] = origin->reg[i];
    new->forked = true;
    new->freeze = op_tab[OP_LFORK].nbr_cycles;
    new->pc = origin->pc;
    new->carry = origin->carry;
    new->fd = -1;
    return new;
}

int inst_lfork(champion_t *champ, core_t *core, code_t desc UNU, int *args)
{
    // debug(champ, core, desc, args);
    champion_t *new = dup_champion(champ);

    if (!new)
        return 0;
    new->pc = (champ->pc + args[0]) % MEM_SIZE;
    while (new->pc < 0)
        new->pc += MEM_SIZE;
    core->champions = realloc_champions(core->champions, new);
    if (!core->champions)
        return -1;
    return 0;
}
