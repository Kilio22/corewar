/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** Takes a file descriptor, and returns the first found line of it.
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"

static char *get_next_newline(int fd, char *line, char **db)
{
    char *buf = malloc(sizeof(char) * (READ_SIZE + 1));
    int n_read;
    char *ptr;

    if (!buf)
        return (NULL);
    n_read = read(fd, buf, READ_SIZE);
    if (n_read == -1 || !line)
        return (free_em(1, buf));
    if (!n_read && !*line)
        return (free_em(2, line, buf));
    buf[n_read] = '\0';
    ptr = my_strchr(buf, '\n');
    if (ptr) {
        *db = my_strdup(ptr + 1);
        return (my_strncat(line, buf, ptr - buf));
    }
    if (n_read != READ_SIZE)
        return (my_strcat(line, buf));
    return (get_next_newline(fd, my_strcat(line, buf), db));
}

char *get_next_line(int fd)
{
    static char *db = NULL;
    char *line = db;
    char *ptr = my_strchr(line, '\n');

    if (!line)
        line = my_strdup("");
    if (!line)
        return (NULL);
    db = NULL;
    if (ptr) {
        db = my_strdup(ptr + 1);
        ptr = my_strndup(line, ptr - line);
        free(line);
        return (ptr);
    }
    return (get_next_newline(fd, line, &db));
}
