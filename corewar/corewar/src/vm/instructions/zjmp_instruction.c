/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

void zjmp_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    int tmp = 0;

    if (!process->carry) {
        move_pc(process, instruction->size);
        return;
    }
    move_pc(process, process->registries[0] % IDX_MOD);
}
