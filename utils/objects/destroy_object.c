/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** destroy_object
*/

#include "utils.h"

void destroy_object(object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    sfClock_destroy(object->clock);
}
