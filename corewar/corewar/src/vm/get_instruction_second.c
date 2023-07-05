/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** get_instruction.c
*/

#include "../../include/corewar.h"

void read_value(field_t *field, int *offset, int size, int *buffer)
{
    *buffer = 0;
    for (int i = 0; i < size; i++) {
        *buffer = *buffer << 8;
        *buffer += field[*offset % MEM_SIZE].value;
        *offset += 1;
    }
    switch (size) {
        case 1:
            *buffer = (char) *buffer;
            break;
        case 2:
            *buffer = (short) *buffer;
            break;
        case 4:
            *buffer = (int) *buffer;
            break;
    }
}

void get_insctruction_loop(instruction_t *instruction, field_t *field,
                            int *sizes, int pos)
{
    int offset = pos + is_a_pcb(instruction->opcode) + 1;
    int pcb = is_a_pcb(instruction->opcode) ?
                        field[(pos + 1) % MEM_SIZE].value : 0;

    for (int i = 3; i > 0; i--) {
        if ((pcb >> (i * 2)) & 3) {
            instruction->params_type[3 - i] = (pcb >> (i * 2)) & 3;
            read_value(field, &offset,
            sizes[(pcb >> (i * 2)) & 3], &instruction->params[3 - i]);
            continue;
        }
        if (!pcb && i == 3) {
            instruction->params_type[3 - i] = 3;
            read_value(field, &offset, sizes[2], &instruction->params[3 - i]);
        }
    }
    instruction->size = offset - pos;
}

instruction_t *check_all_params_valid(instruction_t *instruction)
{
    for (int i = 0; i < 3; i++) {
        if (instruction->params_type[i] == T_REG &&
        (instruction->params[i] < 1 || instruction->params[i] > 16))
            return instruction_error(instruction);
    }
    return instruction;
}
