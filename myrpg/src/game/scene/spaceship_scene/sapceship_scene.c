/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../../include/game/rpg.h"

static const char *SPACE_S = "./assets/SpaceShip/space.png";
static const char *TARTINE_S = "./assets/SpaceShip/tartine.png";
static const char *SUN = "./assets/SpaceShip/Sun.png";
static const char *BAREN = "./assets/SpaceShip/Baren.png";
static const char *ICE = "./assets/SpaceShip/Ice.png";
static const char *LAVA = "./assets/SpaceShip/Lava.png";
static const char *TERRAN = "./assets/SpaceShip/Terran.png";

void just_check(object_t *object);
update_current(SpaceShip *scene);

void bark(void *obj)
{
    return;
}

void on_spaceship_render(void *scene)
{
    SpaceShip *scene_menu = (SpaceShip *) scene;
    sfVector2f position = {0, 0};

    update_stats_panel(scene_menu);
    update_current(scene_menu);
    event_planete(scene_menu);
    scene_menu->dpl -= 0.25 / 6;
    if (scene_menu->dpl < 0) {
        scene_menu->dpl = 2;
        scene_menu->dpr *= -1;
    }
    reduce_pixel(scene_menu->bufsc);
    sfTexture_updateFromPixels(scene_menu->bufsc->tx,
        scene_menu->bufsc->pixels, scene_menu->bufsc->width,
        scene_menu->bufsc->height, 0, 0);
    OSP(scene_menu->mouse,  i_to_f(
        sfMouse_getPositionRenderWindow(ENGINE->window)));
    scene_render(scene_menu->objects);
}

void on_spaceship_event(void *scene, sfEvent *event)
{
    SpaceShip *scene_menu = (SpaceShip *) scene;

    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        scene_change(SHELL);
    if (event->type == sfEvtMouseButtonPressed)
        scene_menu->press = true;
    if (event->type == sfEvtMouseButtonReleased)
        scene_menu->press = false;
    scene_handle_events(scene_menu->objects, event);
}

void *on_spaceship_create(void)
{
    SpaceShip *scene = malloc(sizeof(SpaceShip));

    scene->ratio = 1;
    scene->objects = 0;
    scene->dpl = 2;
    scene->dpr = 1;
    scene->planete = NULL;
    scene->press = false;
    scene->n_stats = 0;
    scene->bufsc = framebuffer_create(1920, 1080);
    scene_add_object(&scene->objects,
        object_create_from_image(SPACE, (loc_t){0, 0}, SPACE_S));
    scene_add_object(&scene->objects,
        object_create_sprite(999, (loc_t){0, 0}, scene->bufsc->sp));
    add_gui_space(scene);
    create_planete(scene,
        (SpacePlanetInit){.obj_pos = (loc_t){960, 540},
            .name = SUN,
            .text = "",
            .text_pos = (loc_t){936, 516},
            .title = "SUN",
            .desc = "Planet: Sun\nDifficulty: *^*\nDesc: "
                    "fait trop chaud",
            .id = -1,
            .difficulty = "IMPOSSIBLE",
            .lock = true,
            .idd = 3000,
            .speed = 0});
    create_planete(scene,
        (SpacePlanetInit){.obj_pos = (loc_t){0, 0},
            .name = BAREN,
            .text = "Baren",
            .title = "BAREN",
            .text_pos = (loc_t){0, 0},
            .desc = "Planet: Baren\nBoss: Nathan\nDesc: "
                    "planete dodo",
            .id = 0,
            .difficulty = "EASY",
            .lock = false,
            .idd = 3001,
            .speed = 0.017});
    create_planete(scene,
        (SpacePlanetInit){.obj_pos = (loc_t){0, 0},
            .name = ICE,
            .text = "Ice",
            .title = "ICE",
            .text_pos = (loc_t){0, 0},
            .desc = "Planet : Ice\nBoss : Dogo\nDesc : On se "
                    "les peles grave ici",
            .id = 1,
            .difficulty = "EASY",
            .idd = 3002,
            .lock = true,
            .speed = 0.015});
    create_planete(scene,
        (SpacePlanetInit){.obj_pos = (loc_t){0, 300},
            .name = LAVA,
            .text = "Lava",
            .title = "LAVA",
            .text_pos = (loc_t){0, 0},
            .desc = "Planet : Lava\nBoss : Bark\nDesc : "
                    "planete de la mer, ha non ?",
            .id = 2,
            .difficulty = "EASY",
            .idd = 3003,
            .lock = true,
            .speed = 0.013});
    create_planete(scene,
        (SpacePlanetInit){.obj_pos = (loc_t){0, 0},
            .name = TERRAN,
            .text = "Terran",
            .title = "TERRAN",
            .text_pos = (loc_t){0, 0},
            .desc =
                "Planet : Terran\nBoss : Lulu, le chat\nDesc "
                ": planete de la terre, c'est pas trop difficile",
            .id = 3,
            .difficulty = "MEDIUM",
            .idd = 3004,
            .lock = false,
            .speed = 0.011});
    create_planete(scene,
        (SpacePlanetInit){.obj_pos = (loc_t){0, 300},
            .name = TERRAN,
            .text = "Tanos",
            .title = "TANOS",
            .text_pos = (loc_t){0, 0},
            .desc = "Planet : Tartine\nBoss : Karim\nDesc : "
                    "tout ce qu'il y a dans la tartine",
            .id = 4,
            .difficulty = "MEDIUM",
            .lock = true,
            .idd = 3005,
            .speed = 0.009});
    create_planete(scene,
        (SpacePlanetInit){.obj_pos = (loc_t){0, 300},
            .name = TERRAN,
            .text = "Tartine",
            .title = "TARTINE",
            .text_pos = (loc_t){0, 0},
            .desc = "Planet : Tartine\nBoss : Karim\nDesc : "
                    "tout ce qu'il y a dans la tartine",
            .id = 4.5,
            .difficulty = "HARD",
            .idd = 3007,
            .lock = false,
            .speed = 0.007});
    create_planete(scene,
        (SpacePlanetInit){.obj_pos = (loc_t){0, 300},
            .name = TARTINE_S,
            .text = "Tartinos",
            .title = "TARTINOS",
            .text_pos = (loc_t){0, 0},
            .desc = "Planet : Tartine\nBoss : Karim\nDesc : "
                    "tout ce qu'il y a dans la tartine",
            .id = 9,
            .difficulty = "HARD",
            .lock = true,
            .idd = 3008,
            .speed = 0.005});
    return scene;
}
