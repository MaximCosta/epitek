/*
** EPITECH PROJECT, 2022
** main
** File description:
** echo $?
*/

#include "my.h"

int main(int ac, char *av[])
{
    data_t *data = init_data();
    if (data == NULL)
        return (84);
    fill_grid(data);
    grid_print(data, 0, 3);
    free_all(data);
    return 0;
}
