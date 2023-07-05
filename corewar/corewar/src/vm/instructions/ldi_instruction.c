/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

void ldi_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    int value1 = instruction->params[0];
    int value2 = instruction->params[1];
    int value3 = instruction->params[2];
    int tmp = process->pos + value1 % IDX_MOD;
    int buff = 0;

    read_value(corewar->vm->fields, &tmp, IND_SIZE, &buff);
    buff += value2;
    tmp = process->pos + buff % IDX_MOD;
    read_value(corewar->vm->fields, &tmp, REG_SIZE, &buff);
    process->registries[value3] = buff;
    process->carry ^= 1;
    move_pc(process, instruction->size);
}
