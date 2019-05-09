/*
** EPITECH PROJECT, 2019
** asm
** File description:
** compile_file
*/

#include <limits.h>
#include <endian.h>
#include <unistd.h>
#include "asm.h"

static int write_char(int fd, char *str)
{
    char byte = 0;

    for (size_t i = 1; str[i]; i++) {
        byte *= 10;
        byte += str[i] - 48;
    }
    if (write(fd, &byte, sizeof(char)) != sizeof(char))
        return -1;
    return 0;
}

static int write_short(int fd, struct instruction *inst, struct label *head,
                        int offset)
{
    int tmp;
    short byte;

    if (inst->id == ID_DIRECT)
        inst = inst->next;
    if (inst->id == ID_LABEL)
        tmp = find_label(head, inst->next->instruction)->offset - offset;
    else
        tmp = my_atoi(inst->instruction);
    if (tmp < SHRT_MIN || tmp > SHRT_MAX)
        return -1;
    byte = tmp;
    byte = htobe16(byte);
    if (write(fd, &byte, sizeof(short)) != sizeof(short))
        return -1;
    return 0;
}

static int write_int(int fd, struct instruction *inst, struct label *head,
                        int offset)
{
    int byte;

    if (inst->id == ID_LABEL)
        byte = find_label(head, inst->next->instruction)->offset - offset;
    else
        byte = my_atoi(inst->instruction);
    byte = htobe32(byte);
    if (write(fd, &byte, sizeof(int)) != sizeof(int))
        return -1;
    return 0;
}

static int write_arguments(struct instruction *inst, struct label *head, int fd,
                            int offset)
{
    int index = check_instruction_occurences(inst->instruction);
    int param_size;
    int n_write;

    inst = inst->next;
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        param_size = get_parameter_size(inst, index);
        if (param_size == 1)
            n_write = write_char(fd, inst->instruction);
        else if (param_size == 2)
            n_write = write_short(fd, inst, head, offset);
        else
            n_write = write_int(fd, inst->next, head, offset);
        if (n_write == -1)
            return -1;
        inst = shift_inst(inst);
    }
    return 0;
}

int compile_file(struct instruction **list, struct label *head, int fd)
{
    int offset = 0;
    int index;
    char code;
    char desc;

    for (size_t i = 0; list[i]; i++) {
        index = check_instruction_occurences(list[i]->instruction);
        code = op_tab[index].code;
        desc = !op_needs_args(index) ? -1 :
get_parameters_code(list[i]->next, index);
        if (write(fd, &code, sizeof(char)) != sizeof(char))
            return -1;
        if (desc != -1 && write(fd, &desc, sizeof(char)) != sizeof(char))
            return -1;
        if (write_arguments(list[i], head, fd, offset) == -1)
            return -1;
        offset += count_instruction_bytes(list[i]);
    }
    return 0;
}
