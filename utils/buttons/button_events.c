/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** button_events
*/

#include "utils.h"

void is_button_hovered(button_t *button, sfRenderWindow *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(button->object.sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, mouse_pos,
    sfRenderWindow_getView(window));

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        set_button_state(button, HOVERED);
    } else {
        set_button_state(button, IDLE);
    }
}

void show_button(button_t *button, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(button->clock);

    if (time.microseconds >= 100000 && button->action_queued == WAITING) {
        button->action_queued = YES;
        sfClock_restart(button->clock);
    }
    display(&button->object, window);
}

sfBool get_button_click(button_t *button, sfRenderWindow *window)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->object.sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, mouse_pos,
    sfRenderWindow_getView(window));

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        set_button_state(button, PRESSED);
        button->action_queued = WAITING;
        sfClock_restart(button->clock);
        return sfTrue;
    }
    return sfFalse;
}
