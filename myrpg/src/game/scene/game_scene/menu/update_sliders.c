/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-flavio.moreno
** File description:
** update_sliders.c
*/

#include "../../../../../include/game/rpg.h"

void just_check(object_t *object);

void update_fps(game *scene, textobject_t *fps_t, V2F slider_p)
{
    if (slider_p.x - 600 > 0)
        textobject_set_string(fps_t, my_itoa(slider_p.x - 600, 0));
    else
        textobject_set_string(fps_t, "0");
    sfRenderWindow_setFramerateLimit(ENGINE->window, slider_p.x - 600);
}

void update_volume(game *scene, textobject_t *fps_t, V2F slider_p)
{
    float percent = 0.00;

    percent = (slider_p.x - 600) * 100;
    percent /= 786;
    if (percent > 0)
        textobject_set_string(fps_t, my_itoa(percent, 0));
    else
        textobject_set_string(fps_t, "0");
    sfMusic_setVolume(music_get_from_uuid(VOICE_OFF)->sf_music, percent);
}

void update_slider(game *scene, slider_t *slider,
void (*act)(game *scene, textobject_t *text, V2F pos))
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(ENGINE->window);
    int diff = TGS(sfSprite_getTexture(slider->slider->sprite)).x / 2;
    V2F slider_p = OGP(slider->slider);

    if (!scene->menu->active)
        return;
    if ((object_on_hover(slider->slider, just_check) || slider->take) && scene->mouse_press
    && OGP(slider->slider).x - diff >= (slider->size.x - diff) &&
    OGP(slider->slider).x + diff <= slider->size.y) {
        OSP(slider->slider, (V2F){mouse.x, OGP(slider->slider).y});
        slider->take = true;
    } else
        slider->take = false;
    if (OGP(slider->slider).x - diff < slider->size.x - diff)
        OSP(slider->slider, (V2F){slider->size.x, OGP(slider->slider).y});
    if (OGP(slider->slider).x + diff > (slider->size.y - diff))
        OSP(slider->slider, (V2F){slider->size.y - (diff * 2), OGP(slider->slider).y});
    TSP(slider->text, (V2F){slider_p.x + (diff * 2), slider_p.y - (diff * 2)});
    act(scene, slider->text, slider_p);
}

void all_slider(game *scene)
{
    static slider_t fps = {.size = {600, 1400}, .take = false};
    static slider_t volume = {.size = {600, 1400}, .take = false};

    fps.slider = OGFuuid_t(&scene->objects, FPS_SLIDER);
    volume.slider = OGFuuid_t(&scene->objects, VOLUME_SLIDER);
    fps.text = TOGFUUID(&scene->objects, TEXT_FPS);
    volume.text = TOGFUUID(&scene->objects, TEXT_VOLUME);
    if (!volume.take)
        update_slider(scene, &fps, &update_fps);
    if (!fps.take)
        update_slider(scene, &volume, &update_volume);
}
