/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** create_champion
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <endian.h>
#include "corewar.h"

int read_header(header_t *header, const char *champ_path)
{
    int fd = open(champ_path, O_RDONLY);

    if (fd == -1)
        return -1;
    if (read(fd, header, sizeof(header_t)) != sizeof(header_t))
        return -1;
    if (be32toh(header->magic) != COREWAR_EXEC_MAGIC)
        return -1;
    return fd;
}

champion_t *create_champion(const char *champ_path)
{
    header_t header = {0, {0}, 0, {0}};
    champion_t *champ;
    int fd = read_header(&header, champ_path);

    if (fd == -1)
        return NULL;
    champ = malloc(sizeof(champion_t));
    if (!champ)
        return NULL;
    my_strcpy(champ->prog_name, header.prog_name);
    champ->prog_size = be32toh(header.prog_size);
    champ->prog_start = NULL;
    for (size_t i = 0; i < REG_NUMBER; i++)
        champ->reg[i] = 0;
    champ->cycles_until_death = CYCLE_TO_DIE;
    champ->pc = 0;
    champ->carry = 0;
    champ->fd = fd;
    return champ;
}
