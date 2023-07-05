/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

void lld_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    int value1 = instruction->params[0];
    int value2 = instruction->params[1];
    int pos = process->pos + value1;

    read_value(corewar->vm->fields, &pos,
                REG_SIZE, &process->registries[value2]);
    process->carry ^= 1;
    move_pc(process, instruction->size);
}
