/*
** EPITECH PROJECT, 2022
** display_welhome
** File description:
** display welcome screen or home screen
*/

#include "rpg.h"

void display_home(home_t *home, sfRenderWindow *window)
{
    display(&home->home, window);
    show_button(&home->play, window);
    sfRenderWindow_drawText(window, home->play.text, NULL);
    show_button(&home->options, window);
    sfRenderWindow_drawText(window, home->options.text, NULL);
    show_button(&home->exit, window);
    sfRenderWindow_drawText(window, home->exit.text, NULL);
}

void display_option(home_t *home, option_t *option, sfRenderWindow *window)
{
    display(&home->home, window);
    display(&option->box, window);
    display(&option->more, window);
    display(&option->less, window);
    display(&option->house, window);
    display(&option->disco, window);
}

void display_volume(option_t *option, sfRenderWindow *window, float volume)
{
    display(&option->title, window);
    option->frame_v.top = (1000.0 - (10 * volume));
    sfSprite_setTexture(option->volume.sprite, option->volume.texture, sfTrue);
    sfSprite_setTextureRect(option->volume.sprite, option->frame_v);
    sfSprite_setPosition(option->volume.sprite, option->volume.pos);
    sfRenderWindow_drawSprite(window, option->volume.sprite, NULL);
}
