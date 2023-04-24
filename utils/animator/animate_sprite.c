/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** animate_sprite
*/

#include "utils.h"

void animate_sprite(object_t *object, unsigned int offset, sfIntRect *limits,
unsigned int steps)
{
    sfIntRect rect = sfSprite_getTextureRect(object->sprite);
    sfVector2u texture_size = sfTexture_getSize(object->texture);
    sfTime time = sfClock_getElapsedTime(object->clock);

    if (!limits) {
        rect.left = (rect.left + rect.width >= texture_size.x) ? 0 :
        rect.left + rect.width + offset;
    } else {
        rect.top = limits->top;
        rect.height = limits->height;
        rect.width = limits->width / steps;
        rect.left = (rect.left + rect.width >= limits->width) ? 0 :
        rect.left + rect.width + offset;
    }
    if (time.microseconds >= 60000) {
        sfSprite_setTextureRect(object->sprite, rect);
        sfClock_restart(object->clock);
    }
}
