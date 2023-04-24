/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** display_game
*/

#include "rpg.h"

void update_game(game_t *game)
{
    game->player.curr_weapon = &game->player.inventory->sword.item;
    move_player(&game->player, &game->menu);
    set_game_cam(game, &game->player);
    display(&game->map, game->window);
    if (game->player.is_attacking == sfTrue) {
        player_attack(&game->player);
        display(&game->player.curr_weapon->game_obj, game->window);
    }
    display(&game->player.object, game->window);
    show_enemies(game->enemies, &game->player, game->window);
    get_player_damage(&game->player, game->enemies);
    show_health(&game->player, game->camera, game->window);
}
