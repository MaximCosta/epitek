/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** get_instruction.c
*/

#include "../../include/corewar.h"

static const int is_indexes[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 1, 1, 0, 0, 0
};

instruction_t *instruction_error(instruction_t *instruction)
{
    free(instruction);
    return NULL;
}

int is_valid_pcb_second(int opcode, int pcb, int i)
{
    int tmp = 0;

    for (int j = 0; j < 4; j++) {
        if (j == 3)
            return 0;
        tmp = (op_tab[opcode - 1].type[(3 - i)] >> j & 1) << j;
        tmp = tmp == 4 ? 3 : tmp;
        if (((pcb >> (i * 2)) & 3) == tmp)
            break;
    }
    return 1;
}

int is_valid_pcb(int opcode, int pcb)
{
    if (!is_a_pcb(opcode))
        return 1;
    if (pcb == 0 || pcb & 3)
        return 0;
    for (int i = 3; i > 0; i--) {
        if ((pcb >> (i * 2)) & 3 && op_tab[opcode - 1].nbr_args < (4 - i))
            return 0;
        if (!((pcb >> (i * 2)) & 3) && op_tab[opcode - 1].nbr_args >= (4 - i))
            return 0;
        if (!is_valid_pcb_second(opcode, pcb, i))
            return 0;
    }
    return 1;
}

void set_sizes_tab(int *sizes, int op)
{
    sizes[2] = (op > 9 && op != 13 && op < 16) ? 2 : 4;
    sizes[2] = is_indexes[op] ? IND_SIZE : sizes[2];
}

instruction_t *get_instruction(field_t *field, int pos)
{
    instruction_t *instruction =
                    (instruction_t *)my_calloc(sizeof(instruction_t));
    int sizes[4] = {0, 1, 0, IND_SIZE};
    int pcb = 0;
    int tmp = 0;
    int offset = 0;

    if (field[pos % MEM_SIZE].value < 1 || field[pos % MEM_SIZE].value > 16)
        return instruction_error(instruction);
    instruction->opcode = field[pos % MEM_SIZE].value;
    if (is_a_pcb(instruction->opcode)) {
        pcb = field[(pos + 1) % MEM_SIZE].value;
        if (!is_valid_pcb(instruction->opcode, pcb))
            return instruction_error(instruction);
    }
    set_sizes_tab(sizes, instruction->opcode);
    instruction->nb_params = op_tab[instruction->opcode - 1].nbr_args;
    my_strcpy(instruction->name, op_tab[instruction->opcode - 1].mnemonique);
    get_insctruction_loop(instruction, field, sizes, pos);
    return check_all_params_valid(instruction);
}
