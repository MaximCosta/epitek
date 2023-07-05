/*
** EPITECH PROJECT, 2022
** src/main
** File description:
** rm -rf --no-preserve-root /
*/

#include "sand.h"

void change_check(int x, int y, sand_t *sand)
{
    int pos[4][2] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

    for (int i = 0; i < 4; i++) {
        if (pos[i][0] < 0 || pos[i][0] >= sand->sx)
            continue;
        if (pos[i][1] < 0 || pos[i][1] >= sand->sy)
            continue;
        sand->maps[pos[i][1]][pos[i][0]] += 1;
    }
    sand->maps[y][x] -= 4;
}

void algo_part1(sand_t *sand)
{
    while (1) {
        sand->maps[sand->sy / 2][sand->sx / 2] += 1;
        is_supof(sand);
        if (sand->cx == -1 || sand->cy == -1)
            break;
        change_check(sand->cx, sand->cy, sand);
    }
}

int main_loop(sand_t *sand)
{
    for (int i = 0; i < sand->loop; i++)
        algo_part1(sand);
    return 0;
}

<<<<<<< HEAD
void free_all(sand_t *sand, char *map)
{
    for (int i = 0; i < sand->sy; i++)
        free(sand->maps[i]);
    free(sand->maps);
    free(map);
    free(sand);
}

=======
>>>>>>> 2190c7fd0ec28ba9b2c6b1d068dc3d21ac3babea
void print_int_map(sand_t *sand)
{
    for (int i = 0; i < sand->sy; i++) {
        for (int j = 0; j < sand->sx; j++)
            printf("%d ", sand->maps[i][j]);
        printf("\n");
    }
}

int main(int ac, char *av[])
{
    sand_t *sand = calloc(sizeof(sand_t), 1);
    char *map = NULL;

    if (ac != 4)
        my_exit("number of arguments is not correct\n", 84);
    if (strlen(av[2]) != 4 || is_unique(av[2]) == 0)
        my_exit("number of element is not correct\n", 84);
    if (is_number(av[3]) == 0)
        my_exit("arguments 3 is not a number\n", 84);
    map = load_file_in_mem(av[1], av[2]);
    sand->loop = atoi(av[3]);
    sand->base = av[2];
    sand->maps = buff_to_int(map, av[2], sand);
    print_int_map(sand);
    main_loop(sand);
    print_map(sand);
    free_all(sand, map);
    return 0;
}
