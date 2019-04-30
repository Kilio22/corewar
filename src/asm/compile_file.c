/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** compile_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int compile_file(char **file, char *filename)
{
    int fd = open(filename, O_TRUNC | O_CREAT | O_WRONLY, 0644);

    if (fd == -1)
        return -1;
    for (size_t i = 0; file[i]; i++) {
        if (compile_line(file[i], fd) == -1) {
            printf("Compilation failed at index : %lu\n", i);
            return -1;
        }
    }
    close(fd);
    return 0;
}
