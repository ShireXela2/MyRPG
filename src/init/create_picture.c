/*
** EPITECH PROJECT, 2022
** create_picture
** File description:
** create images sprite and textures
*/

#include "rpg.h"

void create_picture(game_t *game)
{
    create_home(game->home, game->font);
    create_option(game->option);
}

void create_home(home_t *home, sfFont *font)
{
    home->home = create_object(HOME_BG, V2F(0, 0));
    home->play = create_visual_button(BUTTONS, V2F(660, 600), &V2F(5, 5),
    &IRECT(0, 33, 31, 31));
    object_center_origin(home->play.object.sprite);
    home->play.text = create_text("Play", font, V2F(660, 710), &V2F(1.5, 1.5));
    home->options = create_visual_button(BUTTONS, V2F(960, 600), &V2F(5, 5),
    &IRECT(0, 66, 31, 31));
    object_center_origin(home->options.object.sprite);
    home->options.text = create_text("Settings", font, V2F(960, 710),
    &V2F(1.5, 1.5));
    home->exit = create_visual_button(BUTTONS, V2F(1260, 600), &V2F(5, 5),
    &IRECT(0, 165, 31, 31));
    object_center_origin(home->exit.object.sprite);
    home->exit.text = create_text("Exit", font, V2F(1260, 710),
    &V2F(1.5, 1.5));
}

void create_option(option_t *option)
{
    option->box = create_object(BOX, V2F(460, 14));
    option->more = create_object(BTN_PLUS, V2F(600, 400));
    option->less = create_object(BTN_MINUS, V2F(828, 400));
    option->house = create_object(HOUSE, V2F(1067, 400));
    option->disco = create_object(DISCO, V2F(1295, 400));
    option->title = create_object(TITLE_O, V2F(660, 100));
    option->volume = create_object(VOLUME, V2F(550, 600));
    option->frame_v = IRECT(0, 500, 600, 100);
}
