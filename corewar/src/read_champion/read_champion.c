/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** read_champion
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"

int read_header(header_t *header, const char *champ_path)
{
    header_t header = {0, {0}, 0, {0}};
    int fd = open(champ_path, O_RDONLY);

    if (fd == -1)
        return -1;
    if (read(fd, header, sizeof(header_t)) != sizeof(header_t))
        return -1;
    if (header->magic != COREWAR_EXEC_MAGIC)
        return -1;
    return 0;
}

chamption_t *create_champion(const char *champ_path)
{
    header_t header;
    chamption_t *champ;

    if (read_header(&header, champ_path) == -1)
        return NULL;
    champ = malloc(sizeof(chamption_t));
    if (!champ)
        return NULL;
    my_strcpy(champ->prog_name, header.prog_name);
    champ->prog_size = header.prog_size;
    for (size_t i = 0; i < REG_NUMBER; i++)
        champ->reg[i] = 0;
    champ->pc = 0;
    champ->carry = 0;
    return champ;
}

chamption_t *read_champion(const char *champ_path)
{
}
