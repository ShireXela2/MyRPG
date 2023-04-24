/*
** EPITECH PROJECT, 2022
** condition
** File description:
** all condition of defender's project
*/

#include "rpg.h"

void condition(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        get_events(game);
    condition_welhome(game);
    condition_game(game);
}

void condition_welhome(game_t *game)
{
    if (game->menu == HOME) {
        play_home(game->music);
        display_home(game->home, game->window);
        event_home(game->home, &game->menu, game->window, game->event);
        return;
    }
    if (game->menu == OPTIONS) {
        play_home(game->music);
        display_option(game->home, game->option, game->window);
        display_volume(game->option, game->window, game->music->volume);
        event_option(game);
        return;
    }
}

void condition_game(game_t *game)
{
    if (game->menu == INVENTORY) {
        update_game(game);
        set_hud_cam(game->camera, game->window);
        show_inventory(game->player.inventory, game->window, game->event);
        return;
    }
    if (game->menu == GAME) {
        update_game(game);
        return;
    }
}
