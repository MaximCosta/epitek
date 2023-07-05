/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-kilyan.cotten
** File description:
** delete_char.c
*/

#include "../include/jobs.h"

void delete_char(char **str, char delete)
{
    char *copy = istrdup(*str);
    int size = strlen(copy);
    int i = 0;

    for (; copy[0]; copy++, i++)
        copy[0] != delete ? (*str)[i] == copy[0] : size--;
    if (!copy)
        free(copy);
    (*str)[size] = '\0';
}
