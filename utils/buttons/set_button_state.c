/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** src/menus/set_button_state.c
*/

#include "utils.h"

void set_button_state(button_t *button, btn_state_t state)
{
    sfIntRect rect = sfSprite_getTextureRect(button->object.sprite);

    button->state = state;
    if (state == IDLE) {
        rect.left = 0;
        sfSprite_setTextureRect(button->object.sprite, rect);
    }
    if (state == HOVERED) {
        rect.left = 33;
        sfSprite_setTextureRect(button->object.sprite, rect);
    }
    if (state == PRESSED) {
        rect.left = 66;
        sfSprite_setTextureRect(button->object.sprite, rect);
    }
}
