/*
** EPITECH PROJECT, 2019
** Test
** File description:
** test for write_header function
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include "asm.h"

const char *name = "name";
const char *cont = "comment";

Test(write_header, not_fulled_struct)
{
    int fd = open("write_header.test", O_CREAT, 00777);
    header_t *header = malloc(sizeof(header_t));

    header->magic = 0;
    my_strcpy(header->prog_name, name);
    header->prog_size = 0;
    my_strcpy(header->comment, cont);
    cr_assert_eq(write_header(fd, header), -1);
}

Test(write_header, wrong_usage_of_write)
{
    int fd = open("write_header.test", O_CREAT, 00777);
    header_t *header = NULL;

    cr_assert_eq(write_header(fd, header), -1);
}
