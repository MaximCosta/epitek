/*
** EPITECH PROJECT, 2022
** check_map
** File description:
** stumper03
*/

#include "sand.h"

int check_map_char(char ch, char *str)
{
    int i;

    for (i = 0; str[i] != 0; i++) {
        if (str[i] == ch || ch == '\n')
            return 1;
    }
    return -1;
}

void check_map(char *str, char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (check_map_char(buffer[i], str) < 0)
            my_exit("char in map is invalid\n", 84);
    }
}
