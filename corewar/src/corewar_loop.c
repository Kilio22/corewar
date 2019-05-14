/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar_loop
*/

#include <endian.h>
#include "corewar.h"

bool op_needs_args(int op_idx)
{
    if (op_idx == OP_LIVE || op_idx == OP_ZJMP)
        return false;
    if (op_idx == OP_FORK || op_idx == OP_LFORK)
        return false;
    return true;
}

static int get_arg(char *arena, char type, int op_idx, int *offset)
{
    int arg = 0;

    for (int i = get_arg_length(type, op_idx); i > 0; i--) {
        arg <<= 8;
        arg += arena[*offset];
        (*offset) = (*offset + 1) % MEM_SIZE;
    }
    return arg;
}

static code_t get_param_code(champion_t *champ, char *arena, int op_idx)
{
    if (!op_needs_args(op_idx))
        return 0;
    return arena[(champ->pc + 1) % MEM_SIZE];
}

static void get_inst_arguments(char *arena, int arg[4], int op_idx, int pc)
{
    code_t code = arena[(pc + 1) % MEM_SIZE];
    char type = 0;
    int offset = (pc + 2) % MEM_SIZE;

    if (!op_needs_args(op_idx)) {
        if (--offset < 0)
            offset += MEM_SIZE;
        arg[0] = get_arg(arena, op_idx == OP_LIVE ? 0b10 : 0b11, op_idx,
&offset);
        return;
    }
    for (int i = 0; i < op_tab[op_idx].nbr_args; i++) {
        type = (code & 0b11000000) >> 6;
        arg[i] = get_arg(arena, type, op_idx, &offset);
        code <<= 2;
    }
}

static int execute_inst(champion_t *champ, char *arena, code_t code, int op_idx)
{
    int args[4];

    get_inst_arguments(arena, args, op_idx, champ->pc);
    return op_tab[op_idx].inst(champ, arena, code, args);
}

static bool is_instruction_valid(champion_t *champ, char *arena, int op_idx)
{
    if (op_idx < 0 || op_idx > (OP_NB - 2))
        return false;
    if (!op_needs_args(op_idx))
        return true;
    if (check_param_bytecode(op_idx, arena[(champ->pc + 1) % MEM_SIZE]) == -1)
        return false;
    return true;
}

static void execute_champions_instruction(champion_t **champions, char *arena)
{
    int op_idx;
    code_t code;

    for (int i = 0; champions[i]; i++) {
        if (champions[i]->freeze > 0)
            continue;
        op_idx = arena[PC] - 1;
        if (!is_instruction_valid(champions[i], arena, op_idx)) {
            PC = (PC + 1) % MEM_SIZE;
            continue;
        }
        code = get_param_code(champions[i], arena, op_idx);
        printf("%d \t===> ", PC);
        printf("Code: %s[%X] \t: ", op_tab[op_idx].mnemonique, op_idx + 1);
        if (execute_inst(champions[i], arena, code, op_idx) == -1) {
            PC = (PC + 1) % MEM_SIZE;
            champions[i]->freeze = 1;
        } else {
            PC = (PC + count_inst_bytes(code, op_idx)) % MEM_SIZE;
            champions[i]->freeze = op_tab[op_idx].nbr_cycles;
        }
    }
}

int loop_corewar(champion_t **champions, int dump)
{
    char *arena = create_arena(champions);

    if (!arena)
        return 84;
    while (!is_game_ended(champions)) {
        if (dump != -1 && !dump--) {
            dump_arena(arena);
            break;
        }
        execute_champions_instruction(champions, arena);
        for (int i = 0; champions[i]; i++) {
            --champions[i]->freeze;
            update_champions_live();
        }
        update_champions_live_status(champions);
    }
    display_winning_champions(champions);
    return 0;
}
