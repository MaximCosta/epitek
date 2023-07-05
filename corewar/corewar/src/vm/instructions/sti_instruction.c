/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

void sti_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    int value1 = instruction->params[0];
    int value2 = instruction->params[1];
    int value3 = instruction->params[2];

    if (instruction->params_type[1] == T_REG)
        value2 = process->registries[value2];
    if (instruction->params_type[2] == T_REG)
        value3 = process->registries[value3];
    write_at_pos(
        corewar->vm->fields,
        value1, process->pos + (value2 + value3) % IDX_MOD,
        REG_SIZE);
    move_pc(process, instruction->size);
}
