/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef ENGINE_H
    #define ENGINE_H

    #include <fcntl.h>
    #include <stdbool.h>
    #include "types.h"
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "graph/graph.h"
    #include "list/list.h"
    #include "scene/scene.h"
    #include "parallax/parallax.h"
    #include "location/location.h"
    #include "music/music.h"
    #include "gc.h"
    #include "stdlib.h"
    #include "stdio.h"
    #include "utils/utils.h"
    #include "utils/libstr.h"
    #include "utils/myfile.h"
    #include "time/time.h"
    #include "object/object.h"
    #include "object/entity/entity.h"
    #include "sound/sound.h"
    #include "gui/gui.h"
    #include "random/random.h"
    #include "settings/settings.h"
    #define ENGINE get_engine()
    #define CAST(type,el) ((type) el)

typedef struct s_engine engine_t;

struct s_engine {

    sfRenderWindow *window;
    scene_manager_t *scene_manager;
    music_manager_t *music_manager;
    sound_manager_t *sound_manager;
    settings_manager_t *settings_manager;
    gui_manager_t *gui_manager;
    sfClock *clock;
    sfFont *default_font;
    float delta_time;
};

engine_t *get_engine(void);

void engine_init(sfRenderWindow *window);

void engine_start(void (*window_handler)(),
            void (*event_handler)(sfEvent *event));

#endif //ENGINE_H
