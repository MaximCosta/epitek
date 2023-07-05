/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

void sub_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    int first_r = process->registries[instruction->params[0]];
    int second_r = process->registries[instruction->params[1]];
    int result = first_r - second_r;

    process->registries[instruction->params[2]] = result;
    process->carry = (result == 0) ? 1 : 0;
    move_pc(process, instruction->size);
}
