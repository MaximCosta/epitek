/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-dante-maxim.costa
** File description:
** main
*/

#include "../include/my.h"

void print_maze(generator_t *maze)
{
    int r;
    for (int i = 0; i < maze->height; i += 2) {
        r = rand() % maze->width;
        for (int j = 0; j < maze->width; j++) {
            printf("*");
        }
        printf("\n");
        for (int l = 0; l < maze->width && i+1 < maze->height &&
        i + 2 != maze->height; l++)
            printf(l == r ? "*" : "X");
        if (i + 2 == maze->height){
            for (int k = 0; k < maze->width-1; k++)
                printf("X");
            printf("*");
        }
        if (i + 2 != maze->height)
            printf("\n");
    }
}

int main(int ac , char **av)
{
    if (ac < 2)
        return 84;
    generator_t *maze = init_struct(atoi(av[1]), atoi(av[2]));
    print_maze(maze);
    free_all(maze);
    return 0;
}
