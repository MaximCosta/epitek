/*
** EPITECH PROJECT, 2022
** tetris [WSL: Ubuntu]
** File description:
** lib2
*/

#include "../include/tetris.h"

char *my_strdump(char *str)
{
    char *new = my_calloc(sizeof(char), my_strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++)
        new[i] = str[i];
    free(str);
    return (new);
}

char *my_strdup(char *str)
{
    char *new = my_calloc(sizeof(char), my_strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++)
        new[i] = str[i];
    return (new);
}

void sort_struct_array(tetris_t *tet, int size)
{
    api_t *tmp;
    int i = 0;

    while (i < size) {
        if (my_strcmp(tet->pieces[i]->name, tet->pieces[i + 1]->name) > 0) {
            tmp = tet->pieces[i];
            tet->pieces[i] = tet->pieces[i + 1];
            tet->pieces[i + 1] = tmp;
            i = 0;
        }
        i++;
    }
}

void verif_bool(int *input, char **argv)
{
    if (optarg == NULL && argv[optind] != NULL && argv[optind][0] != '-')
        exit(84);
    *input = true;
}

void verif_input(int args[3], int *input, char **argv)
{
    int val;

    if (optarg == NULL && (argv[optind] == NULL || argv[optind][0] == '-'))
        exit(84);
    val = my_atoi(optarg ? optarg : argv[optind]);
    *input = args[0];
    if ((val > args[1] && args[1] != -1) || val < args[2] || val >= 1000)
        my_exit(84, "Error: invalid argument\n");
    *input = val;
}
