/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** subtitle.c
*/

#include "../../../../../include/game/rpg.h"

void subtitle_animation(LoadScene *load_scene)
{
    textobject_t *subtile =
        textobject_get_from_uuid(&load_scene->objects, SUBTITLE);
    static int e = 0;

    if (load_scene->index_subtitle > 5)
        return;
    if (elapsed_time_milliseconds(50, &load_scene->delta_time.time,
                                    &load_scene->delta_time.saved)) {
        e++;
        if (load_scene->subtitle[load_scene->index_subtitle][load_scene->sub]
                != '\0'
            && e > 40) {
            load_scene->text = my_strcat_char(load_scene->text,
                load_scene
                    ->subtitle[load_scene->index_subtitle][load_scene->sub]);
            load_scene->sub += 1;
        }
    }
    textobject_set_string(subtile, load_scene->text);
}

char **get_subtitle(char **subtitle)
{
    subtitle = malloc(sizeof(char *) * 6);

    subtitle[0] = my_strdup(
        "Wake up to Reality ! Nothing ever goes as"
        " planned in this accursed world. The longer you live, the more you"
        " will realize,");
    subtitle[1] = my_strdup(
        "That the only things that truly exist in"
        " this reality are merely pain, suffering and futility. listen..."
        "everywhere you look\n in this world, wherever there is light,");
    subtitle[2] = my_strdup(
        "there will always be shadows to be found "
        "as well. As long as there is a concept of victors, the vanquished "
        "will also exist.\nThe selfish intent of wanting to preserve peace,");
    subtitle[3] = my_strdup(
        " initiates wars. And Haired is born in order"
        " to protect Love. There are nexuses, causal relationships that cannot"
        " be separated.");
    subtitle[4] = my_strdup(
        "I want to sever the fate of this world. A world"
        " of only victors. A world of only Peace. A world of only Love.");
    subtitle[5] = my_strdup("I will create such a world. i am ... The Ghost"
                            " of the Utchiwa.");
    return subtitle;
}
