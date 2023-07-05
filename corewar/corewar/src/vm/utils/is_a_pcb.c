/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** is_a_pcb.c
*/

#include "../../../include/corewar.h"

int is_a_pcb(int opcode)
{
    return !(opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15);
}
