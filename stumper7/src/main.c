/*
** EPITECH PROJECT, 2022
** main
** File description:
** man man
*/

#include "my.h"

int check_intput(char *ln)
{
    int i = 0;

    for (; ln[i] && '0' <= ln[i] && ln[i] <= '9'; i++);
    if (ln[i++] != ',')
        return 1;
    for (; ln[i] && ln[i] != '\n' && '0' <= ln[i] && ln[i] <= '9'; i++);
    if (ln[i - 1] == ',' || (ln[i] != 0 && ln[i] != '\n'))
        return 1;
    return 0;
}

int get_input(int *x, int *y, int i, game_t *gm)
{
    char *line = NULL;
    ssize_t read = 0;
    size_t len = 0;

    if (printf("Player %d> ", i % 2 + 1) == -1)
        exit(84);
    read = getline(&line, &len, stdin);
    if (read == -1)
        exit(0);
    if (len < 3 || check_intput(line))
        return (1);
    *x = atoi(line);
    for (; *line != ','; line++);
    *y = atoi(++line);
    if (0 <= *x && *x < gm->size && 0 <= *y && *y < gm->size)
        if (gm->board[*y][*x] == '.')
            return (0);
    return (1);
}

int main_game(game_t *gm)
{
    int err = 0;
    int win = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; !win; i++) {
        y = -1;
        x = -1;
        for (; get_input(&x, &y, i, gm););
        gm->board[y][x] = gm->pl[i % 2];
        print_board(gm);
        win = check_win(gm);
        if (win)
            err = printf("Player %d won!\n", i % 2 + 1);
        if (err == -1)
            exit(84);
    }
    return (0);
}

int main(int ac, char *av[])
{
    game_t *game = check_args(ac, av);
    init_board(game);
    print_board(game);
    main_game(game);
    free_all(game);
    return (0);
}
