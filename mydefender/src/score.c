/*
** EPITECH PROJECT, 2022
** mydefender [WSL: Ubuntu]
** File description:
** score
*/

#include "defender.h"

void update_score(game_t *game)
{
    int score = asSec(game->time);

    if (score != game->score && game->score % 10 == 0 && game->score != 0)
        game->money += 10;
    game->score = score;
    print_score(game);
}

void print_score(game_t *game)
{
    int iscore = game->score;
    sfFloatRect rec;
    int base = 10;
    char *score;
    char *str;

    if (game->state != PLAY)
        return;
    score = my_calloc(1UL, 0, 11);
    my_itoa(iscore, score, base);
    str = concat("score ", score);
    sfText_setCharacterSize(game->mn->text, 18);
    sfText_setString(game->mn->text, str);
    rec = sfText_getGlobalBounds(game->mn->text);
    sfText_setPosition(
        game->mn->text, gp(game->wx - rec.width - 10, rec.height));
    sfRenderWindow_drawText(game->wd, game->mn->text, NULL);
    free(score);
    free(str);
    print_money(game);
}

void print_money(game_t *game)
{
    int iscore = game->money;
    sfFloatRect rec;
    int base = 10;
    char *money;
    char *str;

    if (game->state != PLAY)
        return;
    money = my_calloc(1UL, 0, 11);
    my_itoa(iscore, money, base);
    str = concat("money ", money);
    sfText_setCharacterSize(game->mn->text, 18);
    sfText_setString(game->mn->text, str);
    rec = sfText_getGlobalBounds(game->mn->text);
    sfText_setPosition(
        game->mn->text, gp(game->wx - rec.width - 10, 2 * rec.height + 10));
    sfRenderWindow_drawText(game->wd, game->mn->text, NULL);
    sfText_setCharacterSize(game->mn->text, 96);
    free(money);
    free(str);
}
