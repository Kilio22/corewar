/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <endian.h>
#include <endian.h>
#include "asm.h"

static int open_dest(const char *file_name)
{
    size_t len = my_strlen(file_name);
    char dest[len + 5];

    if (my_str_ends_with(file_name, ".s")) {
        my_strncpy(dest, file_name, len - 2);
        my_strcpy(dest + len - 2, ".cor");
    } else {
        my_strcpy(dest, file_name);
        my_strcpy(dest + len, ".cor");
    }
    return open(dest, O_CREAT | O_TRUNC | O_WRONLY, 0664);
}

static int write_binary_code(struct instruction **list, struct label *head,
                                header_t *header, int fd)
{
    int n_return = 0;

    if (write_header(fd, header) == -1)
        n_return = -1;
    if (!n_return && compile_file(list, head, fd) == -1)
        n_return = -1;
    close(fd);
    return n_return;
}

static int build_binary_code(struct instruction **list, const char *file_name,
                                header_t *header)
{
    struct label *head = NULL;
    int prog_size = get_labels(list, &head);
    int n_return = 0;
    int fd;

    if (prog_size == -1 || check_if_labels_exist(list, head) == -1) {
        if (head)
            destroy_labels(head);
        return -1;
    }
    header->prog_size = htobe32(prog_size);
    fd = open_dest(file_name);
    if (fd == -1) {
        n_return = -1;
    } else if (write_binary_code(list, head, header, fd) == -1)
        n_return = -1;
    if (head)
        destroy_labels(head);
    return n_return;
}

int main(int argc, char const *argv[])
{
    struct instruction **list;
    header_t header = {htobe32(COREWAR_EXEC_MAGIC), {0}, 0, {0}};
    char **file;
    int n_return = 0;

    if (argc != 2)
        return 84;
    file = get_file(argv[1], &header);
    if (!file)
        return 84;
    list = load_instructions(file);
    my_free_fields(file);
    if (!list)
        return 84;
    if (check_syntax_loop(list) == 84)
        n_return = 84;
    if (!n_return && build_binary_code(list, argv[1], &header) == -1)
        n_return = 84;
    destroy_instruction_list(list);
    return n_return;
}
