/*
** EPITECH PROJECT, 2022
** check_file.c
** File description:
** stumper02
*/

#include "./include/my.h"

int check_file(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'X' || str[i] == '.')
            continue;
        if (str[i] == '\n')
            continue;
        exit(84);
    }
    check_lines(str);
    return 0;
}

void check_count(int count, int check)
{
    if (count != check)
        exit(84);
}

int check_lines(char *buffer)
{
    int count = 0;
    int check = 0;

    for (int i = 0; buffer[i] != '\n'; i++) {
        count++;
    }
    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n') {
            check_count(count, check);
            check = 0;
            continue;
        }
        check++;
    }
    return 0;
}
