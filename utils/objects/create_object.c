/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_object
*/

#include "my.h"
#include "utils.h"

void object_center_origin(sfSprite *sprite)
{
    sfVector2f origin;
    sfFloatRect bounds = sfSprite_getLocalBounds(sprite);

    origin.x = bounds.width / 2;
    origin.y = bounds.height / 2;
    sfSprite_setOrigin(sprite, origin);
}

object_t create_object(char *filename, sfVector2f pos)
{
    object_t object;

    object.clock = sfClock_create();
    object.sprite = sfSprite_create();
    if (my_strcmp(filename, ""))
        object.texture = sfTexture_create(1, 1);
    else
        object.texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(object.sprite, object.texture, sfFalse);
    sfSprite_setPosition(object.sprite, pos);
    object.scale = V2F(1, 1);
    object.pos = pos;
    return object;
}
