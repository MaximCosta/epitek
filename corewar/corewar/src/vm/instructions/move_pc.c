/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** move_pc.c
*/

#include "../../../include/corewar.h"

void move_pc(process_t *process, int offset)
{
    process->pos += offset;
    if (process->pos < 0)
        process->pos += MEM_SIZE;
    process->pos %= MEM_SIZE;
}
