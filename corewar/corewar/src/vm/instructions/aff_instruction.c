/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cycle.c
*/

#include "../../../include/corewar.h"

void aff_instruction(
    corewar_t *corewar, instruction_t *instruction, process_t *process)
{
    int value = process->registries[instruction->params[2]];
    char ch = value % 256;

    my_putchar(ch);
    move_pc(process, instruction->size);
}
