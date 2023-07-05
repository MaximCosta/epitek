/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** write_at_pos.c
*/

#include "../../../include/corewar.h"

static int get_real_place(int pos)
{
    while (pos < 0)
        pos += MEM_SIZE;
    return pos % MEM_SIZE;
}

void write_at_pos(field_t *fields, int value, int pos, int id)
{
    int i = 0;

    for (int i = 4; i > 0; i--) {
        fields[get_real_place((pos + i) % MEM_SIZE)].value = value % 256;
        fields[get_real_place((pos + i) % MEM_SIZE)].owner_id = id;
        value /= 256;
    }
}
