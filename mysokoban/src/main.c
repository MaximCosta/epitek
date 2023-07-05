/*
** EPITECH PROJECT, 2022
** sokoban [WSL: Ubuntu]
** File description:
** main
*/

#include "my.h"

void init(void)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
}

void get_maps(game_t *game, char *filename)
{
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    int i = -1;
    int bi = -1;

    if ((fp = fopen(filename, "r")) == NULL)
        exit(EXIT_FAILURE);
    game->maps = (char **) my_calloc_2d(8UL, game->h + 2);
    game->boxs = (int *) my_calloc(4, -1, game->box + 1);
    game->boys = (int *) my_calloc(4, -1, game->box + 1);
    while ((read = getline(&game->maps[++i], &len, fp)) != -1) {
        for (int j = 0; game->maps[i][j]; j++)
            maps_condi(game, i, j, &bi);
        game->w = MAX(game->w, read);
    }
    fclose(fp);
}

game_t *load_game(char *argv[])
{
    char *filename = argv[1];
    game_t *game = malloc(sizeof(game_t));

    game->w = 0;
    countlines(filename, game);
    get_maps(game, filename);
    return game;
}

int check_win(game_t *game)
{
    for (int i = 0; i < game->box; i++)
        if (game->maps[game->boys[i]][game->boxs[i]] != 'O')
            return 0;
    my_exit_ncurses(0);
    return 0;
}

int main(int args, char *argv[])
{
    game_t *game;

    if (args != 2)
        exit(EXIT_FAILURE);
    if (my_strcmp(argv[1], "-h") == 0)
        write(1,
            "USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file representing "
            "the warehouse map, containing '#' for walls,\n\t\t'P' for the "
            "player, 'X' for boxes and 'O' for storage locations.\n",
            172);
    game = load_game(argv);
    init();
    for ( ; ; loop_main(game, argv));
    return 0;
}
