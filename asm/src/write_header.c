/*
** EPITECH PROJECT, 2019
** write_header
** File description:
** write the struct header_t in a file
*/

#include <unistd.h>
#include "op.h"
#include "asm.h"

int write_header(const int fd, const header_t *header)
{
    ssize_t n_write = 0;

    if (!header)
        return -1;
    n_write = write(fd, header, sizeof(header_t));
    if (n_write != sizeof(header_t))
        return -1;
    return 0;
}
