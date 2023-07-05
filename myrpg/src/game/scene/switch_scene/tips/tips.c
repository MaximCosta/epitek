/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** tips.c
*/

#include "../../../../../include/game/rpg.h"

char **add_tips(void)
{
    char **tips = malloc(sizeof(char *) * 10);

    tips[0] = my_strdup("Youth want space; old age, time.\n");
    tips[1] = my_strdup("Writing is the only area of absolute freedom.\n");
    tips[2] = my_strdup("Time is only the activity of space.\n");
    tips[3] = my_strdup("Violence fuels wars and starves peoples.\n");
    tips[4] = my_strdup("Beauty is in the eyes of the beholder.\n");
    tips[5] = my_strdup("Memory is the invisible presence.\n");
    tips[6] = my_strdup("To be or not to be, that is the question.\n");
    tips[7] = my_strdup(
        "When a man learns to love, he must bear the risk of hatred.\n");
    tips[8] =
        my_strdup("It will be a new world… A world of truth, not lies.\n");
    tips[9] = my_strdup("We watching you !\n");
    return tips;
}
