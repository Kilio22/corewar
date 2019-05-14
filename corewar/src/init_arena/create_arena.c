/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** create_arena
*/

#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"

static int put_bytecode_at_adress(char *arena, int fd, int address, int size)
{
    char buf[size + 1];
    char *ptr = buf;
    ssize_t n_read = read(fd, buf, size);

    if (n_read != size)
        return -1;
    for (int i = address; size--; i++) {
        if (i >= MEM_SIZE)
            i %= MEM_SIZE;
        arena[i] = *ptr++;
    }
    return 0;
}

char *create_arena(champion_t **champions)
{
    char *arena = malloc(sizeof(char) * MEM_SIZE);
    int n_return;

    if (!arena)
        return NULL;
    my_memset(arena, '\0', MEM_SIZE);
    for (int i = 0; champions[i]; i++) {
        n_return = put_bytecode_at_adress(arena, champions[i]->fd,
champions[i]->pc, champions[i]->prog_size);
        if (n_return == -1) {
            free(arena);
            return NULL;
        }
    }
    return arena;
}
