/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** get_events
*/

#include "rpg.h"

void get_events(game_t *game)
{
    if (game->event.type == sfEvtClosed || game->event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed || sfEvtKeyReleased ||
    sfEvtMouseButtonPressed) {
        toggle_inventory(&game->event, &game->menu, &game->player.is_inv_open);
        get_player_movement(&game->player, &game->event, &game->menu);
        get_player_actions(&game->player, &game->event, &game->menu);
    }
}
