/*
** EPITECH PROJECT, 2022
** envent_welhome
** File description:
** check all event for welcome screen and home screen
*/

#include "rpg.h"

void home_actions(home_t *home, game_state_t *menu, sfRenderWindow *window)
{
    if (home->play.action_queued == YES) {
        home->play.action_queued = NO;
        *menu = GAME;
    }
    if (home->options.action_queued == YES) {
        home->options.action_queued = NO;
        *menu = OPTIONS;
    }
    if (home->exit.action_queued == YES) {
        home->exit.action_queued = NO;
        sfRenderWindow_close(window);
    }
}

void event_home(home_t *home, game_state_t *menu, sfRenderWindow *window,
sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft) {
            get_button_click(&home->play, window);
            get_button_click(&home->options, window);
            get_button_click(&home->exit, window);
        }
    } else {
        is_button_hovered(&home->play, window);
        is_button_hovered(&home->options, window);
        is_button_hovered(&home->exit, window);
    }
    home_actions(home, menu, window);
}

void event_option(game_t *game)
{
    if ((check_mouse(game->event.mouseButton, VOL_UP_R) == sfTrue ||
        sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) &&
        game->music->volume < 100.0)
        game->music->volume += 10.0;
    if ((check_mouse(game->event.mouseButton, VOL_DOWN_R) == sfTrue ||
        sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) &&
        game->music->volume > 0.0)
        game->music->volume -= 10.0;
    if (check_mouse(game->event.mouseButton, HOME_R) == sfTrue ||
        sfKeyboard_isKeyPressed(sfKeyH) == sfTrue)
        game->menu = HOME;
    if (check_mouse(game->event.mouseButton, OPT_EXIT_R) == sfTrue)
        sfRenderWindow_close(game->window);
}
