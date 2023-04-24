/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** object_edit
*/

#include "utils.h"

void edit_object(object_t *object, sfVector2f *scale, sfVector2f *pos,
float rotation)
{
    if (scale) {
        sfSprite_setScale(object->sprite, *scale);
        object->scale = *scale;
    }
    if (pos) {
        sfSprite_setPosition(object->sprite, *pos);
        object->pos = *pos;
    }
    if (rotation != -1)
        sfSprite_setRotation(object->sprite, rotation);
}
