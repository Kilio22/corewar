/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** dump_arena
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"

static char *char_to_hexstr(char nbr)
{
    char *base = "0123456789ABCDEF";
    int base_length = 16;
    int r;
    unsigned char result = nbr;
    char str[3] = {'0', '0', 0};

    for (int i = 0; result != 0; i++) {
        r = result % base_length;
        result = result / base_length;
        str[i] = base[r];
    }
    return (my_strdup(my_revstr(str)));
}

static char *int_to_hexstr(int nbr)
{
    char *base = "0123456789ABCDEF";
    int base_length = 16;
    int r;
    unsigned int result;
    char str[50] = "";

    if (nbr < 0)
        result = 4294967296 + nbr;
    else
        result = nbr;
    if (nbr == 0)
        str[0] = '0';
    for (int i = 0; result != 0; i++) {
        r = result % base_length;
        result = result / base_length;
        str[i] = base[r];
    }
    return (my_strdup(my_revstr(str)));
}

static int print_arena_memory(char *ptr)
{
    char *str;

    for (int i = 0; i < 32; i++) {
        str = char_to_hexstr(ptr[i]);
        if (!str)
            return -1;
        my_putchar(' ');
        my_putstr(str);
        free(str);
    }
    return 0;
}

void dump_arena(char *arena)
{
    char *str;

    for (int i = 0; i < MEM_SIZE; i += 32) {
        str = int_to_hexstr(i);
        if (!str)
            return;
        my_putstr(str);
        for (int i = my_strlen(str); i < 5; i++)
            my_putchar(' ');
        free(str);
        my_putchar(':');
        if (print_arena_memory(arena + i) == -1)
            return;
        my_putchar(' ');
        my_putchar('\n');
    }
}
