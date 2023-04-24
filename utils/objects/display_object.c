/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** display_object
*/

#include "utils.h"

void display(object_t *object, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, object->sprite, NULL);
}
