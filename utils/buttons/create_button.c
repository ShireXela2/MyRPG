/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** create_button
*/

#include "utils.h"

void text_center_origin(sfText *text)
{
    sfVector2f origin;
    sfFloatRect bounds = sfText_getGlobalBounds(text);

    origin.x = bounds.left + bounds.width / 2;
    origin.y = bounds.top + bounds.height / 2;
    sfText_setOrigin(text, origin);
}

sfText *create_text(char *string, sfFont *font, sfVector2f pos,
sfVector2f *scale)
{
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, string);
    text_center_origin(text);
    sfText_setPosition(text, pos);
    if (scale != NULL)
        sfText_setScale(text, *scale);
    return text;
}

button_t create_visual_button(char *filename, sfVector2f pos,
sfVector2f *scale, sfIntRect *area)
{
    button_t button;

    button.object = create_object(filename, pos);
    if (scale != NULL) {
        button.scale = *scale;
        sfSprite_setScale(button.object.sprite, *scale);
    }
    if (area != NULL)
        sfSprite_setTextureRect(button.object.sprite, *area);
    button.clock = sfClock_create();
    button.action_queued = NO;
    button.text = NULL;
    button.state = IDLE;
    return button;
}

button_t create_text_button(char *text, sfFont *font, sfVector2f pos,
sfVector2f *scale)
{
    button_t button;

    button.scale = *scale;
    button.object = create_object("", pos);
    sfSprite_setScale(button.object.sprite, button.scale);
    button.text = create_text(text, font, pos, scale);
    button.state = IDLE;
    return button;
}
