/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-flavio.moreno
** File description:
** read_insctructions.c
*/

#include "../../include/corewar.h"

read_champ_t *read_champ(champion_t *champion)
{
    read_champ_t *champ = (read_champ_t *) my_calloc(sizeof(read_champ_t));
    char *str = (char *) my_calloc(sizeof(char) * (champion->prog_size + 1));

    champ->field =
        (field_t *) my_calloc(sizeof(field_t) * champion->prog_size);
    if (read(champion->fd, str, champion->prog_size) != champion->prog_size) {
        free(champ);
        close(champion->fd);
        return (NULL);
    }
    for (int i = 0; i < champion->prog_size; i++)
        champ->field[i].value = str[i];
    champ->len = champion->prog_size;
    close(champion->fd);
    return champ;
}
