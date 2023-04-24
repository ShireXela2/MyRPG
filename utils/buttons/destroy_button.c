/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** destroy_button
*/

#include "utils.h"

void destroy_button(button_t *button)
{
    destroy_object(&button->object);
    sfClock_destroy(button->clock);
    sfText_destroy(button->text);
}
