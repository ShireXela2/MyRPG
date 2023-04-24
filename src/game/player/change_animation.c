/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** change_animation
*/

#include "rpg.h"

void set_idle(sfEvent *evt, player_t *player)
{
    if (evt->key.code == sfKeyD || evt->key.code == sfKeyQ)
        sfSprite_setTextureRect(player->object.sprite, SIDE_IDLE);
    if (evt->key.code == sfKeyZ)
        sfSprite_setTextureRect(player->object.sprite, UP_IDLE);
    if (evt->key.code == sfKeyS)
        sfSprite_setTextureRect(player->object.sprite, DOWN_IDLE);
}

void change_side_animation(sfBool *is_key_pressed, sfEvent *evt,
player_t *player)
{
    if (evt->type == sfEvtKeyPressed && *is_key_pressed == sfFalse)
        *is_key_pressed = sfTrue;
    else {
        set_idle(evt, player);
        *is_key_pressed = sfFalse;
    }
}

void change_animation(sfBool *is_key_pressed, sfEvent *evt, player_t *player)
{
    sfIntRect rect = sfSprite_getTextureRect(player->object.sprite);

    if (evt->type == sfEvtKeyPressed && *is_key_pressed == sfFalse) {
        rect.left = 0;
        sfSprite_setTextureRect(player->object.sprite, rect);
        *is_key_pressed = sfTrue;
    } else if (evt->type == sfEvtKeyReleased && *is_key_pressed == sfTrue) {
        set_idle(evt, player);
        *is_key_pressed = sfFalse;
    }
}
